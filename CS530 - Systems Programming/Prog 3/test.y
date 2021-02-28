
/*
Test.y (Bison File)
CS530 TTH 19:00 Assignment #3
Allan Sur     821444631 cssc3022
Aung Lin Htet 823702029 cssc3041
*/

%{
#include<stdio.h>
#include<string.h>

extern int yyparse();
extern int yylex();
extern FILE* yyin;
extern char* yytext;


/* Defined our error statement here along with the reason*/
void yyerror(const char *s){
	fprintf(stderr, "Reason: %s, %s", s, yytext);
}
/* Defined all of our tokens to be used for the parser */
%}

%token ID
%token NXT_LIN
%token EQU
%token OP
%token OPEN_P
%token CLOSE_P
%token SEMI_C


/*Grammar Rule Specifications */
%%
prog:
	prog assignment NXT_LIN 	{printf("Valid --------------------   \n\n");}
	| prog error NXT_LIN 			{printf("Invalid --------------------   \n\n");}
	| prog expression NXT_LIN {printf("Valid --------------------   \n\n");}
	|	expression NXT_LIN			{printf("Valid --------------------   \n\n");}
	| assignment NXT_LIN			{printf("Valid --------------------  \n\n");}
	| prog NXT_LIN						{;}
	| error NXT_LIN 					{printf("Invalid--------------------   \n\n");}
	| NXT_LIN									{;};

/*Assignment only has 1 way to work so we only need 1 rule */
assignment: ID EQU expression SEMI_C;


/*These are all the forms that expressions could take on for our assignment #3 */
expression:
	ID OP ID
	| OPEN_P expression CLOSE_P
	| expression OP ID
	| ID OP OPEN_P expression CLOSE_P;

/* More C code but to run the entire prog this time */
/*We just open the file passed to it by the command line and read it then call yyparse() to parse it */
%%
int main(int argc, char *argv[]){
	printf("\n");	// Just making it a bit more organized.
	yyin = fopen(argv[1], "r"); //Opening and setting our file to yyin.
	yyparse(); //Call our yyparse method to do the parsing.
	printf("Program has now run successfully, exiting...s\n");
	return 0;
}
