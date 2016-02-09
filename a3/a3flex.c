#include <stdio.h>
#include "myheader.h"
extern int yylex();
extern YYSTYPE yylval;
extern char* yytext;

main()
{	
	int i =0;
	while(i<5){
		if(yylex()==INTEGER){
			printf("TOKEN INTEGER Value %d, Text>%s<\n",yylval.integer, yytext );
		}
		i++;
	}
    
} 
