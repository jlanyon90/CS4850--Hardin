%{
#include <stdlib.h>
#include "y.tab.h"
%}
%%
[0-9]+  { yylval.integer = atoi(yytext); return NUM;}
"\n"      {return ENDOFLINE;} 
.       return *yytext;

%%

int yywrap(){
    return 1;
}
