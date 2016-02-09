#include "y.tab.h"

extern int yylex(void);
extern FILE* yyin;
int token = 1;
int stringCount = 0;
int symbolCount = 0;
char strings[MAX_STRING][MAX_STRING];
char symbols[MAX_STRING][MAX_STRING];

int main()
{
    printf("Begin Entering Expressions: \n");
    /* yyin    = fopen("test.txt", "r"); */
    yyin = stdin;
    while (token != 0) {
      token = yylex();
      switch (token) {
        case 1:
          /* integer */
          printf("Token: INTEGER, value %d, Text >%d<\n", INTEGER, yylval.val);
          break;
        case 2:
          /* OPA */
          printf("Token: OPA, value %d, Text >%c<\n", ADD, yylval.sym);
          break;
        case 3:
          /* OPM */
          printf("Token: OPM, value %d, Text >%c<\n", MULTIPLY, yylval.sym);
          break;
        case 4:
          /* OPMOD */
          printf("Token: OPMOD, value %d, Text >%c<\n", MOD, yylval.sym);
          break;
        case 5:
          /* OPPOW */
          printf("Token: OPPOW, value %d, Text >%c<\n", POW, yylval.sym);
          break;
        case 6:
          /* OPCOMP */
          printf("Token: OPCOMP, value %d, Text >%s<\n", COMP, yylval.string);
          break;
        case 7:
          /* OPASSIGN */
          printf("Token: OPASSIGN, value %d, Text >%c<\n", ASSIGN_TOKEN, yylval.sym);
          break;
        case 8:
          /* OPLOGIC */
          printf("Token: OPLOGIC, value %d, Text >%c<\n", LOGIC_TOKEN, yylval.sym);
          break;
        case 9:
          /* OPNOT */
          printf("Token: OPNOT, value %d, Text >%c<\n", NOT_TOKEN, yylval.sym);
          break;
        case 10:
          /* LP */
          printf("Token: LP, value %d, Text >%c<\n", LPAR, yylval.sym);
          break;
        case 11:
          /* RP */
          printf("Token: RP, value %d, Text >%c<\n", RPAR, yylval.sym);
          break;
        case 12:
          /* LB */
          printf("Token: LB, value %d, Text >%c<\n", LBRAC, yylval.sym);
          break;
        case 13:
          /* RB */
          printf("Token: RB, value %d, Text >%c<\n", RBRAC, yylval.sym);
          break;
        case 14:
          /* String */
          printf("Token: STRING, value %d, Text >%s<\n", STRING, yylval.string);
          strncpy(&strings[stringCount][0], yylval.string, MAX_STRING);
          stringCount++;
          break;
        case 15:
          /* Symbol */
          printf("Token: SYMBOL, value %d, Text >%s<\n", SYMBOL, yylval.string);
          strncpy(&symbols[symbolCount][0], yylval.string, MAX_STRING);
          symbolCount++;
          break;
        case 16:
          /* Float */
          printf("Token: FLOAT, value %d, Text >%f<\n", FLOAT, yylval.fval);
          break;
        case 999:
          /* STOP */
          break;
        default:
          break;
      }
    }

    /* Print all Strings */
    printf("\nStrings Found:\n");
    while ( stringCount != 0 ) {
      printf("%s\n", &strings[stringCount - 1][0]);
      stringCount--;
    }

    /* Pring all Symbols */
    printf("\nSymbols Found:\n");
    while ( symbolCount != 0 ) {
      printf("%s\n", &symbols[symbolCount - 1][0]);
      symbolCount--;
    }

    return 0;
}
