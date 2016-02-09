%{
#include <stdlib.h>
#include "y.tab.h"
#include "symboltable.h"
%}
DIGIT [0-9]
WS [ \t]
%s skip
%%
{WS}+ ;
{DIGIT}+ { yylval.integer = atoi(yytext); return INT_TOKEN; }
{DIGIT}+"."{DIGIT}* { sscanf(yytext,"%lf", &yylval.real); return REAL_TOKEN;}
(?i:and) {return AND_TOKEN;}
(?i:or)	{return OR_TOKEN;}
(?i:xor) {return XOR_TOKEN;}
(?i:honk) {return HONK;}
(?i:not) {return NOT_TOKEN;}
(?i:grip) {ifrec *i;
            yylval.ifptr = i; 
            return IF_TOKEN;}
(?i:slip) {return ELSE_TOKEN;}
(?i:gripslip) {return ELSEIF_TOKEN;}
<skip>'.' {yylval.string = strdup(yytext); return IFINS;}
<skip>(?i:straight) {return ENDIF_TOKEN;}
\"(\\.|[^"])*\" {yylval.string = strdup(yytext); return STRING_TOKEN;}
[a-zA-Z]+ {	yylval.string = strdup(yytext);
			symrec *s;
    		s = getsym(yylval.string);
    		if(s!=0){
    			if(s->type == 'r'){
    				return RSYMBOL;
    			}else if(s->type == 'i'){
    				return ISYMBOL;
    			}else if(s->type == 's'){
    				return STRSYMBOL;
    			}
    		}else{
			 return SYMBOL;
    		}
		  }
"+"     {return PLUS;}
"-"     {return MINUS; }
"/"     {return DIVIDE;}
"*"     {return MULTIPLY;}
"%"     {return MOD;}
"<"	    {return LESS;}
">"	    {return GREATER;}
"<="	{return LESS_EQUAL;}
">="	{return GREATER_EQUAL;}
"="	    {return EQUAL;}
"!="	{return NOT_EQUAL;}
"("		{return LPARENT;}
")"		{return RPARENT;}
"<-"	{return ASSIGNMENT;}	


"\n" { return ENDOFLINE;  }
%%
 void begin(){
    BEGIN(skip);
 }
 void begin2(){
    BEGIN(INITIAL);
 }
 int yywrap() { return(1); }
