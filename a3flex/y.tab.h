#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING 256
int yylex();

enum yytokentype {
    INTEGER = 1,
    ADD = 2,
    MULTIPLY = 3,
    MOD = 4,
    POW = 5,
    COMP = 6,
    ASSIGN_TOKEN = 7,
    LOGIC_TOKEN = 8,
    NOT_TOKEN = 9,
    LPAR = 10,
    RPAR = 11,
    LBRAC = 12,
    RBRAC = 13,
    STRING = 14,
    SYMBOL = 15,
    FLOAT = 16,
    STOP = 999
};

union yylval {
  int val;
  float fval;
  char sym;
  char string[MAX_STRING];
} yylval;
