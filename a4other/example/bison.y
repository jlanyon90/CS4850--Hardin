/* Bison input file : */
/* ---START--- */
%{
 
void yyerror(const char *s);
 
%}
 
%token NUM POWER
 
%%
 
s  : e s1         { printf("\n"); }
   ;
 
s1 : POWER e s1   { printf(" **"); }
   | /* Empty */
   ;
 
e  : t e1
   ;
 
e1 : '+' t e1     { printf(" +"); }
   | '-' t e1     { printf(" -"); }
   | /* Empty */
   ;
 
t  : f t1
   ;
 
t1 : '*' f t1     { printf(" *"); }
   | '/' f t1     { printf(" /"); }
   | /* Empty */
   ;
 
f  : '(' e ')'
   | NUM          { printf(" %d ",$1); }
   ;
 
%%
 
#include <stdio.h>
 
int main(int argc, char * argv[]) {
  extern FILE * yyin;
 
  if (argc == 1) {
    printf("Reading text from standard input...\n");
  }
  else if (argc == 2) {
    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
      printf("ERROR - Could not open file \"%s\"\n", argv[1]);
      exit(1);
    }
  }
  else {
    printf("Usage: %s or %s \n", argv[0], argv[0]);
    exit(1);
  }
 
  int result = yyparse();
  printf("There were %d syntax errors\n", yynerrs);
  return result;
}
 
extern char *yytext;
extern int yylineno;
 
void yyerror(const char *s) {
  printf("%s at line %d with \"%s\"\n", s, yylineno, yytext);
}
 
/* ---END--- */