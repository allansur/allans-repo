Allan Sur
cssc3022
CS530, 7:00PM Fall 2020
XBD README

File Manifest:
The files for this project include:
- hexdump.cpp
- Makefile
- ReadMe.txt

Compile Instructions:
- Navigate to folder with the hexdump.cpp and Makefile in it and text file you want to dump.
- Command line instruction: make
- Then you can either run xbd <filename> for hexadecimal
- xbd -b <filename> for binary
- xbd -a <filename> both hexadecimal and binary
- "-b" will output the binary dump of the target file

Design Descisions:
- Instead of using a char buffer, I decided that I would just make everything from the target file into a string.
- I figured that since I am better at string manipulation I would focus my strengths on that.
- All of the file print outs are formatted before they print and do not use another function.
- The ostringstream came in very handy for when I had to convert values from hex to binary or from strings to hex
- I also decided to use an external function in order to convert from hexadecimal to binary as I thought that this in the same function for the printing would've been to overwhelming and confusing
- In order to keep track and keep spaces between the correct amount of characters, I made a loop that would insert a space between each of the sets 

Extra Features:
- I added one extra feature, and that is the "-a" command. This command prints both the hex and binary dump

Bugs/Deficiencies:
- There are no Bugs
- I think that my while loops could've been a bit more compacted which would speed up the runtime

Lessons Learned:
- I had never really delved deep into C++ but this project taught me a lot about the inner workings of C++
- The Makefile creation also taught me alot about how programs are compiled.
- I think the one most important lesson that I learned was just how important keeping organized and clean code is especially for something like this being able to track your spot in the program is vital.