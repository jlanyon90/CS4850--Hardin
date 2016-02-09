/* Lex input file : */
/* ---START--- */
%{
 
#include "y.tab.h"
extern int yylval;         /* <--- not needed for Bison, needed for Yacc */
 
%}
 
%option yylineno
 
%%
 
\n       { return EOF; }
[ \t]    { /* Ignore whitespace */; }
"**"     { return POWER; }
[0-9]+   { yylval = atoi(yytext); return NUM; }
.        { return yytext[0]; }
 
%%
 
/* ---END--- */