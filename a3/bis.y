%{
#include <stdio.h>
%}
%union{
double real;
int integer;
char string[100];
}

%token <integer> INTEGER

%%
line: INTEGER
	;