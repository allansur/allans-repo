Team:
Allan Sur 821444631
Naomi Ocampo 821897499
Riana Hernandez

EDORAS:
Naomi: cssc3001
Allan: cssc3022
Riana: cssc3006

CS530 TTH Leonard Fall 2020

FILENAME: README

File Manifest:
-  Calculation.cpp
-Calculation.h
- Disassembler.cpp
- Disassembler.h
- makefile
- printRec.cpp
- printer.h
- ReadMe.txt
- Symtab.cpp
- symtab.h 



Compile Instructions:
$ make
- This will compile all necessary files and make an executable called "dis"


Operating instructions:
- type "dis <filename>.obj
- must include in the same directory a .list, .sym, and .obj file
- the program will automatically scan for the .list and .sym flies and populate their respective areas.
- if any file is not included, the program will exit immediately with a message asking for the required file

Design Decisions:
- One of our major design decisions was using maps to hold things such as the symbol table and op table allowing for faster retrieval and searching.
- Instead of putting everything in the Disassembler.cpp file, we opted to organize and populate other header and .cpp files to make the program more readable and allow methods for use in other classes.
- Another decision was the idea of making our symtab modular. Rather than holding absolute symbols and relative symbols all in the same table, our program will create 2 different maps that will hold these symbols allowing for more accurate retrieval and helps to prevent mixups when trying to access a specific symbol.
- Another significant design decision was rather than using the std::cout method of debugging, we opted to install and use GDB to help with this process. This was a significant factor as using gdb was new to the entire team and took some time to full understand. 
- The way that we found our format was also a new design decision. The first thing we did was check if this format was format 1. If it wasn't we would get the n_I_flags from the opcode for our line, then we would also retrieve the x_b_p_e flags using our hexadecimal to binary method and then take a substring to get these flags. The later part was a bit easier, just checking if the specific flags were either true or false and by doing so we were able to get the correct format for each opcode given.


Deficiencias/Bugs:
- The first deficiency is that the program will sometimes return an out_of_range error after compilation of all files when trying to run the program with the correct .obj file. The program compiles successfully however and when run through gdb with proper breakpoints returns no errors and exits with code 1.

Lessons Learned:
- One of the first lessons that we all learned was just how important documentation is. For a project of this size and scope, one of the first issues that we ran into was the lack of documentation from all parties which made it almost impossible to figure out what the other person was trying to accomplish.
- The second thing that we learned was the use of useful variable names. In the beginning we were naming variables arbitrary things or ambiguously and it was impeding progression as the code was not completed understandable at first glance. 
- We also learned the importance of time management. For a project of this size and scale alongside its complexities, time management was essential to even getting a skeleton of this project up and working. 
- Lastly, we learned how to use a version control system. For this project, writing on Google Docs would not have been efficient or even remotely reasonable. So for this project, we created a private GitHub repository and were able to track changes, updates, and even new feature implementations to allow for constant backtracking in the project if something failed or was broken and also allowed for us to each work on our part of the project in tandem without worrying about breaking someone else's code while we were working on our own. Version control systems are a vital part of the software engineering experience and learning to use one fully and understanding how it works was learned to the fullest in this project.
- extra note: We also learned just how incredibly hardworking and intelligent people who make these systems are.