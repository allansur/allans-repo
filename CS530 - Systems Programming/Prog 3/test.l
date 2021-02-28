/*
Test.l (Flex) File
CS530 TTH 19:00 Assignment #3
Allan Sur     821444631 cssc3022
Aung Lin Htet 823702029 cssc3041
*/

/*Declared our libraries here*/
%{
#include<stdio.h>
#include"y.tab.h"
%}

/*Token definitions here*/
/*Had to include ECHO in order to print out to the console and show the line */
%%
[A-Za-z][_A-Za-z0-9]*  {ECHO; return ID;}
[\n]									{ECHO; return NXT_LIN;}
[\t]+ 								{ECHO;}
"="										{ECHO; return EQU;}
"+"										{ECHO; return OP;}
"-"										{ECHO; return OP;}
"/"										{ECHO; return OP;}
"*"										{ECHO; return OP;}
"%" 									{ECHO; return OP;}
"("										{ECHO; return OPEN_P;}
")"										{ECHO; return CLOSE_P;}
";"										{ECHO; return SEMI_C;}
.                     {ECHO;}

%%
// Must include this yywrap() to return 1 when our input is exhausted
int yywrap() {return 1;}
