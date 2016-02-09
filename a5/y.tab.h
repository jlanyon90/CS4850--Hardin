/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT_TOKEN = 258,
    REAL_TOKEN = 259,
    STRING_TOKEN = 260,
    PLUS = 261,
    MINUS = 262,
    DIVIDE = 263,
    MULTIPLY = 264,
    RPARENT = 265,
    LPARENT = 266,
    MOD = 267,
    LESS = 268,
    GREATER = 269,
    LESS_EQUAL = 270,
    GREATER_EQUAL = 271,
    EQUAL = 272,
    NOT_TOKEN = 273,
    NOT_EQUAL = 274,
    AND_TOKEN = 275,
    OR_TOKEN = 276,
    XOR_TOKEN = 277,
    ENDOFLINE = 278
  };
#endif
/* Tokens.  */
#define INT_TOKEN 258
#define REAL_TOKEN 259
#define STRING_TOKEN 260
#define PLUS 261
#define MINUS 262
#define DIVIDE 263
#define MULTIPLY 264
#define RPARENT 265
#define LPARENT 266
#define MOD 267
#define LESS 268
#define GREATER 269
#define LESS_EQUAL 270
#define GREATER_EQUAL 271
#define EQUAL 272
#define NOT_TOKEN 273
#define NOT_EQUAL 274
#define AND_TOKEN 275
#define OR_TOKEN 276
#define XOR_TOKEN 277
#define ENDOFLINE 278

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 19 "a5bison.y" /* yacc.c:1909  */

double real;
int integer;
char *string;

#line 106 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
