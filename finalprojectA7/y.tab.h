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
    IF_TOKEN = 265,
    IFINS = 266,
    PLUS = 267,
    MINUS = 268,
    DIVIDE = 269,
    MULTIPLY = 270,
    RPARENT = 271,
    LPARENT = 272,
    MOD = 273,
    LESS = 274,
    GREATER = 275,
    LESS_EQUAL = 276,
    GREATER_EQUAL = 277,
    EQUAL = 278,
    NOT_TOKEN = 279,
    NOT_EQUAL = 280,
    AND_TOKEN = 281,
    OR_TOKEN = 282,
    XOR_TOKEN = 283,
    ELSE_TOKEN = 284,
    ELSEIF_TOKEN = 285,
    ENDIF_TOKEN = 286,
    ENDOFLINE = 287,
    ASSIGNMENT = 288,
    HONK = 289
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
#define IF_TOKEN 265
#define IFINS 266
#define PLUS 267
#define MINUS 268
#define DIVIDE 269
#define MULTIPLY 270
#define RPARENT 271
#define LPARENT 272
#define MOD 273
#define LESS 274
#define GREATER 275
#define LESS_EQUAL 276
#define GREATER_EQUAL 277
#define EQUAL 278
#define NOT_TOKEN 279
#define NOT_EQUAL 280
#define AND_TOKEN 281
#define OR_TOKEN 282
#define XOR_TOKEN 283
#define ELSE_TOKEN 284
#define ELSEIF_TOKEN 285
#define ENDIF_TOKEN 286
#define ENDOFLINE 287
#define ASSIGNMENT 288
#define HONK 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 58 "a7bison.y" /* yacc.c:1909  */

	double real;
	int integer;
	char *string;
	ifrec * ifptr;

#line 129 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
