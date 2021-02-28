##MakeFile for Assignment #3##
##CS530 TTH 19:00 Fall 2020 ##
##Assignment #3 Simple Parser##
##Allan Sur     821444631,  cssc3022##
##Aung Lin Htet 823702029,  cssc3041##

default:
	clear
	yacc -d test.y
	lex test.l
	gcc lex.yy.c y.tab.c -o parser

clean:
	clear
	rm y.tab.c lex.yy.c y.tab.h parser
