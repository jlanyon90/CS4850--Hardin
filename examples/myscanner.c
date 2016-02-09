#include <stdio.h>
#include "myscanner.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

char *names [] = {NULL, "db_type", "db_name","db_table_prefix","db_port"};
int main(void){
	int ntoken,vtoken;
	ntoken = yylex();
	while(ntoken){
		printf("%d\n",ntoken );
		if(yylex()!= COLON){
			printf("Syntax ERROR\n");
			return 1;
		}
		vtoken =yylex();
		switch(ntoken){
			case TYPE:
			case NAME:
			case TABLE_PREFIX:
				if(vtoken!= IDENTIFIER){
					printf("EXPECTED IDENTIFIER\n");
					return 1;
				}
				printf("%s is set to %s\n",names[ntoken], yytext);
				break;
			case PORT:
				if(vtoken!= INTEGER){
						printf("Expected integer\n");
						return 1;
				}
				printf("%s is set to %s\n",names[ntoken], yytext);
				break;
			default:
				printf("Syntax ERROR\n");
		}
		ntoken = yylex();
	}//end while

	return 0;
}