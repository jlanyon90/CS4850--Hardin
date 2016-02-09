%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <string.h>

    char * create_list();
    void add(char* array, char input);
    int yyerror(char* s);
    int main(void);
%}
%union{
    char list[100];
    char character;
    int integer;
};

%token <integer> NUM
%token <character> PLUS
%token <character> MINUS
%token <character> MULTIPLY
%token <character> DIVIDE
%token ENDOFLINE
%right NEGATIVE
%type <list> Exp
%%

Statement: 
    | Statement Line
;
Line: Exp ENDOFLINE{ printf("Result -> %s\n", $1);  }
    | ENDOFLINE
;
Exp:  Exp PLUS Exp {add($$,$2);printf("+");}
    |   Exp MULTIPLY Exp {add($$,$2);printf("*");}
    |   Exp MINUS Exp {add($$,$2);printf("-");}
    |   Exp DIVIDE Exp {add($$,$2);printf("/");}
    |   MINUS Exp %prec NEGATIVE {add($$,$1);printf("-");}
    |   NUM     {   char buf[3];
                    sprintf(buf,"%d", $1);
                    strcpy($$,buf); 
                    printf(">%s<",$$);
                    printf("%d", yylval.integer);
                }
;
%%

void add(char* array, char input){
    printf("HERE");
    int length = strlen(array);
    array[length] = input +'0';
}

int main(){
    yyparse();

}

int yyerror (char *msg) {
    return printf ("error YACC: %s\n", msg);
}
