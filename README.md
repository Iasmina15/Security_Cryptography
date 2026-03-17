1. Implementation Approach
This program implements the Caesar Cipher specifically for binary file processing. On the part of encryption, the program is based on the formula: E = (message + key) mod 256,
where message is the original byte, key is the secret key (whose value can be changed, as of now it shifts all characters by 3 positions), and 256 represents the full range of
an 8-bit ASCII character.
To process binary files whether they are MP3s, MP4s or any other types, the program opens the files in "rb" (Read Binary) and "wb" (Write Binary) modes and processes them
byte-by-byte. Since the program reads one byte at a time, it allows it to handle files of 10KB or larger with minimal RAM usage.

3. How To Compile
The program can be compiled using any C compiler (tested with GCC).
Command needed: gcc test1.c -o test1.exe

4. How To Execute
To tell whether you want to use decryption or encryption, the program required a mode flag: -e for encryption, -d for decryption as well as the input filename and the output.
Order: the first filename provided is treated as the SOURCE, whereas the second filename provided is treated as the DESTINATION. The flags -e or -d can be places anywhere.

5. Example Usage
Encrypting a Video file (in this case). We have an example video file in this repository that was used to test this program.
To encrypt it, we run the command: test1.exe Video1.mp4 -e secret.mp4
To decrypt it (restore it to the original), we run the command: test1.exe secret.mp4 -d video.mp4
After doing these commands, we can notice that the file "video.mp4" we created after decrypting is the same as the original "Videe01.mp4" file. Also, the "secret.mp4" file will
appear corrupted as it cannot be opened, nor played.
