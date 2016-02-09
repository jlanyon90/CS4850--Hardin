%{
#include "y.tab.h"
%}

%%

[0-9]+\.[0-9]+ { yylval.fval = atof(yytext); return FLOAT; }
\.[0-9]+ { yylval.fval = atof(yytext); return FLOAT; }
[-1-9]+\.[0-9]+ { yylval.fval = atof(yytext); return FLOAT; }
\-\.[0-9]+ { yylval.fval = atof(yytext); return FLOAT; }
[0-9]+   { yylval.val = atoi(yytext); return INTEGER; }
[-1-9]+[0-9]  { yylval.val = atoi(yytext); return INTEGER; }
[\+|\-]  { yylval.sym = yytext[0]; return ADD; }
[\*|/]   { yylval.sym = yytext[0]; return MULTIPLY; }
[\%]	 { yylval.sym = yytext[0]; return MOD; }
[\^] 	 { yylval.sym = yytext[0]; return POW; }
[\<|\>]   { memset(yylval.string, '\0', MAX_STRING); strncpy(&yylval.string[0],&yytext[0],1); return COMP; }
"=="   { memset(yylval.string, '\0', MAX_STRING); strncpy(&yylval.string[0],&yytext[0],2); return COMP; }
"<="   { memset(yylval.string, '\0', MAX_STRING); strncpy(&yylval.string[0],&yytext[0],2); return COMP; }
">="   { memset(yylval.string, '\0', MAX_STRING); strncpy(&yylval.string[0],&yytext[0],2); return COMP; }
"!="   { memset(yylval.string, '\0', MAX_STRING); strncpy(&yylval.string[0],&yytext[0],2); return COMP; }
"="   { yylval.sym = yytext[0]; return ASSIGN_TOKEN; }
[\AND|\OR|\NAND|\NOR]   { yylval.sym = yytext[0]; return LOGIC_TOKEN; }
'!'   { yylval.sym = yytext[0]; return NOT_TOKEN; }
"("      { yylval.sym = yytext[0]; return LPAR; }
")"      { yylval.sym = yytext[0]; return RPAR; }
"{"      { yylval.sym = yytext[0]; return LBRAC; }
"}"      { yylval.sym = yytext[0]; return RBRAC; }
\"(\\.|[^"])*\"      { memset(yylval.string, '\0', MAX_STRING); 
					   strncpy(&yylval.string[0],&yytext[0], MAX_STRING); 
					   return STRING; 
					  }
[a-zA-Z]+     { memset(yylval.string, '\0', MAX_STRING); 
								 strncpy(&yylval.string[0],&yytext[0], MAX_STRING); 
								 return SYMBOL; 
							   }
<<EOF>>  { return 0; }
[ \t\n]+ { }
.        { printf("ERROR!\n"); exit(1); }
%%
int yywrap(){
    return 1;
}