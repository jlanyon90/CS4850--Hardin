%{
#include <stdlib.h>
#include "y.tab.h"
#include "myheader.h"
%}


DIGIT [0-9]
%%
{DIGIT}+    {yylval.integer = atoi(yytext); return INTEGER;}


%%

int yywrap(void)
{
	return 1;
}
