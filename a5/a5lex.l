%{
#include <stdlib.h>
#include "y.tab.h"
%}
DIGIT [0-9]
WS [ \t]
%%
{WS}+ ;
{DIGIT}+ { yylval.integer = atoi(yytext); return INT_TOKEN; }
{DIGIT}+"."{DIGIT}* { sscanf(yytext,"%lf", &yylval.real); return REAL_TOKEN;}
(?i:and) {return AND_TOKEN;}
(?i:or)	{return OR_TOKEN;}
(?i:xor) {return XOR_TOKEN;}
[a-zA-Z]+ {yylval.string = strdup(yytext); return STRING_TOKEN;}
"+" { return PLUS;}
"-" {return MINUS; }
"/" {return DIVIDE;}
"*" {return MULTIPLY;}
"%" {return MOD;}
"<"	{return LESS;}
">"	{return GREATER;}
"<="	{return LESS_EQUAL;}
">="	{return GREATER_EQUAL;}
"=="	{return EQUAL;}
"!"		{return NOT_TOKEN;}
"!="	{return NOT_EQUAL;}
"("		{return LPARENT;}
")"		{return RPARENT;}	


"\n" { return ENDOFLINE;  }
%%
 int yywrap() { return(1); }
