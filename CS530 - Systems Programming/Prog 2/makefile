#Riana Hernandez, cssc3006
#Naomi Ocampo,  cssc3001
#Allan Sur,  cssc3022 

#CS530 Fall 2020
#Project #2, Dissassembler
#makefile.txt




CXX = g++
CXXFLAGS = -std=c++11 -g
OBJECTS = Disassembler.o symtab.o printRec.o Calculation.o

dis: $(OBJECTS)
	$(CXX) $(OBJECTS) -o dis

Disassembler.o : Disassembler.cpp Calculation.h symtab.h printer.h
	$(CXX) -c Disassembler.cpp

printer.o : printRec.cpp printer.h
	$(CXX) -c printRec.cpp

symtab.o : Symtab.cpp symtab.h
	$(CXX) -c Symtab.cpp

calculate.o : Calculation.cpp Calculation.h
	$(CXX) -c Calculation.cpp

clean:
	rm *.o
.PHONY: dis Disassembler printer symtab calculate