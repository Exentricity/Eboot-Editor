#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

/*
	Arg 0 = exe file path
	Arg 1 = File input path
	Arg 2 = bytes?
*/

int main(int argc, char* argv[])
{
	if (argc < 5)
	{
		std::cerr << "Usage: " << argv[0] << " <file> <address> <numBytes> <bytes> [<address> <numBytes> <bytes> ...]\n";
		return EXIT_FAILURE;
	}

	std::string fileName = argv[1];
	std::size_t address;
	std::uint32_t bytes;

	std::ifstream file(argv[1], std::ios::binary);
	if (!file)
	{
		std::cerr << "Error opening " << argv[0];
		return EXIT_FAILURE;
	}

	// Get size of file
	file.seekg(0, std::ios::end); // start at top of file and go to end
	std::streampos fileSize = file.tellg(); // store into fileSize
	file.seekg(0, std::ios::beg); // go back to beginning of file?

	// Read file into buffer
	std::vector<char> buffer(fileSize);
	file.read(buffer.data(), fileSize);

	// Parse multiple address and arguments, count the bytes and pair them
	for (int i = 2; i < argc;) {
		std::size_t address;
		int numBytes;

		std::stringstream ss;
		ss << std::hex << argv[i++];
		ss >> address;
		address -= 0x10000;
		ss.clear();
		ss << argv[i++];
		ss >> numBytes;

		// Parse the specified number of bytes from the next argument
		std::string bytesStr = argv[i++];
		if (bytesStr.size() != numBytes * 2)
		{
			std::cerr << "Error: expected " << numBytes << " bytes but got " << bytesStr.size() / 2 << "\n";
			return 1;
		}

		// Write the specified number of bytes to the specified address in the buffer
		for (int x = 0; x < numBytes; ++x)
		{
			int byte;
			ss.clear();
			ss << std::hex << bytesStr.substr(x * 2, 2);
			ss >> byte;
			buffer[address + x] = byte;
		}
	}

	file.close();
	std::ofstream outFile(fileName, std::ios::binary);
	outFile.write(buffer.data(), buffer.size());

	return EXIT_SUCCESS;
}