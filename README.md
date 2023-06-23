# EBOOT.ELF Editor by Quinn

## Usage:
#### 1. Open a terminal in this file location
#### 2. Arguments: < filePath > | < address > | < number of bytes to write > | < bytes >
#### 3. Supports multiple pairs of address + byte combinations for writing many addresses

## Example:
### Multiple address writes:
#### PowerShell: ./EbootEditor.exe "C:/Users/User/Desktop/EBOOT.ELF" 00275AAA 4 12345678 00275BBB 8 ABCDEFF012345678
#### Cmd: EbootEditor.exe "C:/Users/User/Desktop/EBOOT.ELF" 00275AAA 4 12345678 00275BBB 8 ABCDEFF012345678
### Single address write:
#### PowerShell: ./EbootEditor.exe "C:/Users/User/Desktop/EBOOT.ELF" 00275AAA 4 12345678
#### Cmd: EbootEditor.exe "C:/Users/User/Desktop/EBOOT.ELF" 00275AAA 4 12345678