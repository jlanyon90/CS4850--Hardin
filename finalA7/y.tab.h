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
    SYMBOL = 261,
    ISYMBOL = 262,
    RSYMBOL = 263,
    STRSYMBOL = 264,
    PLUS = 265,
    MINUS = 266,
    DIVIDE = 267,
    MULTIPLY = 268,
    RPARENT = 269,
    LPARENT = 270,
    MOD = 271,
    LESS = 272,
    GREATER = 273,
    LESS_EQUAL = 274,
    GREATER_EQUAL = 275,
    EQUAL = 276,
    NOT_TOKEN = 277,
    NOT_EQUAL = 278,
    AND_TOKEN = 279,
    OR_TOKEN = 280,
    XOR_TOKEN = 281,
    ENDOFLINE = 282,
    ASSIGNMENT = 283,
    HONK = 284
  };
#endif
/* Tokens.  */
#define INT_TOKEN 258
#define REAL_TOKEN 259
#define STRING_TOKEN 260
#define SYMBOL 261
#define ISYMBOL 262
#define RSYMBOL 263
#define STRSYMBOL 264
#define PLUS 265
#define MINUS 266
#define DIVIDE 267
#define MULTIPLY 268
#define RPARENT 269
#define LPARENT 270
#define MOD 271
#define LESS 272
#define GREATER 273
#define LESS_EQUAL 274
#define GREATER_EQUAL 275
#define EQUAL 276
#define NOT_TOKEN 277
#define NOT_EQUAL 278
#define AND_TOKEN 279
#define OR_TOKEN 280
#define XOR_TOKEN 281
#define ENDOFLINE 282
#define ASSIGNMENT 283
#define HONK 284

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 69 "a7bison.y" /* yacc.c:1909  */

	double real;
	int integer;
	char *string;

#line 118 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
