/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "a7bison.y" /* yacc.c:339  */

#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 0
#else
# define YYERROR_VERBOSE 0
#endif
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symboltable.h"
symrec *symtable = (symrec *)0;

symrec *putsym(char * symname, char *symdata, char symtype)
{
	symrec * ptr;
	ptr = (symrec *) malloc(sizeof(symrec));
	ptr->name = (char *) malloc(strlen(symname)+1);
	ptr->data = (char *) malloc(strlen(symdata)+1);
	ptr->type = (char) malloc(sizeof(symtype));
	strcpy(ptr->name, symname);
	strcpy(ptr->data, symdata);
	ptr->type = symtype;
	ptr->next = (struct symrec *)symtable;
	symtable = ptr;
	return ptr;
}

symrec * getsym(char * symname)
{	
	symrec *ptr;
	for(ptr = symtable; ptr!= (symrec *) 0; ptr=(symrec *)ptr->next){
		if(strcmp(ptr->name,symname)==0){
			return ptr;
		}
	}
	return 0;	
}

install ( char *symname, char *symdata, char symtype)
{
	symrec *s;
	s = getsym(symname);
	if (s == 0){
		s = putsym(symname,symdata,symtype);
	}else{
		s->type = symtype;
		s->data = symdata;
		printf("%s is already defined\n", symname );
	}
}

contextcheck( char *symname )
{
	if ( getsym(symname) == 0 )
	printf("%s is an undeclared identifier\n", symname );
}



#line 132 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 69 "a7bison.y" /* yacc.c:355  */

	double real;
	int integer;
	char *string;

#line 236 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 251 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   332

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  30
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   113,   113,   114,   116,   117,   118,   119,   124,   125,
     126,   127,   129,   130,   131,   132,   133,   134,   135,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   170,   171,   181,
     189,   199,   209,   219,   230,   231,   232,   235,   238,   241,
     242,   246,   255,   264,   273,   282,   291,   302,   305,   308,
     311,   314,   317,   320,   323,   326,   329,   332,   335,   338,
     341,   344,   347,   350,   353,   356,   359,   362,   365,   368,
     371,   375,   378,   382,   384,   390,   395,   401,   406,   411,
     416,   421,   426,   431,   436,   442
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_TOKEN", "REAL_TOKEN",
  "STRING_TOKEN", "SYMBOL", "ISYMBOL", "RSYMBOL", "STRSYMBOL", "PLUS",
  "MINUS", "DIVIDE", "MULTIPLY", "RPARENT", "LPARENT", "MOD", "LESS",
  "GREATER", "LESS_EQUAL", "GREATER_EQUAL", "EQUAL", "NOT_TOKEN",
  "NOT_EQUAL", "AND_TOKEN", "OR_TOKEN", "XOR_TOKEN", "ENDOFLINE",
  "ASSIGNMENT", "HONK", "$accept", "lines", "line", "iexpr", "rexpr",
  "sexpr", "compare", "strcompare", "numcompare", "printer", "assign",
  "reassign", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284
};
# endif

#define YYPACT_NINF -21

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-21)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -21,   140,   -21,   -21,   -21,   -21,   -20,    -9,     0,     9,
      -2,    12,   -21,   289,   -21,   187,   210,    75,   191,   -21,
     -21,    11,    23,    35,   289,   289,   289,   289,   -21,   -21,
     -21,   163,   228,   268,    55,    -2,     7,    20,   302,    54,
     289,     7,     7,     7,     7,     7,     7,     7,     7,     7,
       7,   -21,   289,     7,     7,     7,     7,     7,     7,     7,
       7,     7,     7,   -21,   289,   289,   289,   289,   289,   289,
     289,   -21,    -2,    -2,    -2,   -21,   -21,   -21,   -21,    20,
     302,    54,    20,   302,    54,    20,   302,    54,    20,   302,
      54,   -21,   -21,   -21,   242,   256,   257,   119,   295,   145,
     152,   -21,   145,   152,   309,   316,   309,   316,   309,   316,
     309,   316,   309,   316,   309,   316,   309,   316,   309,   316,
     309,   316,   145,   152,   -21,   145,   152,   309,   316,   309,
     316,   309,   316,   309,   316,   309,   316,   309,   316,   309,
     316,   309,   316,   309,   316,     5,    71,   -21,    20,   302,
      54,    54,    54,    54,    54,    54,   146,   146,   146,   -21,
       7,     7,   145,   152,   145,   152
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,    12,    19,    37,     0,    18,    36,    39,
       0,     0,    11,     0,     3,     0,     0,     0,     0,    44,
      45,     0,     0,     0,     0,     0,     0,     0,    18,    36,
      39,     0,     0,     0,     0,     0,     0,    82,    81,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     4,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     5,     0,     0,     0,     0,     0,     0,
       0,     6,     0,     0,     0,     7,     8,     9,    10,    84,
      85,    86,    90,    91,    92,    93,    94,    95,    87,    88,
      89,    17,    35,    49,     0,     0,     0,     0,     0,    13,
      22,    42,    14,    23,    15,    30,     0,    31,    16,    34,
      58,    60,    62,    64,    66,    68,    70,    72,    74,    76,
      78,    80,    24,    20,    43,    25,    21,    28,    26,    29,
      27,    33,    32,    59,    57,    63,    61,    67,    65,    71,
      69,    75,    73,    79,    77,    40,    41,    38,     0,     0,
      51,    52,    53,    54,    55,    56,    46,    47,    48,    50,
       0,     0,    13,    22,    24,    20
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -21,   -21,   -21,    -1,    64,   126,    -6,   -21,   -21,   -21,
     -21,   -21
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    14,   148,   149,    33,    18,    19,    20,    21,
      22,    23
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      15,     3,     4,     5,    34,    28,    29,    30,    24,    31,
       3,     4,    37,    10,    28,    29,    41,    42,    43,    25,
      11,    44,    36,    79,    82,    85,    88,    35,    26,    96,
      40,    41,    42,    43,    94,    97,    44,    27,    76,    99,
     102,   104,   106,   108,   110,   112,   114,   116,   118,   120,
      77,   122,   125,   127,   129,   131,   133,   135,   137,   139,
     141,   143,    78,   145,    64,    16,   156,   157,   158,    93,
       0,    94,    94,    94,    32,     0,     0,    38,     0,    72,
      73,    74,    53,    54,    55,    64,     0,    56,    80,    83,
      86,    89,    65,    66,    67,    68,    69,     0,    70,    95,
      98,     0,    71,     0,   100,   103,   105,   107,   109,   111,
     113,   115,   117,   119,   121,     0,   123,   126,   128,   130,
     132,   134,   136,   138,   140,   142,   144,    17,   146,   160,
      41,    42,    43,    91,     0,    44,    95,    95,    95,    39,
       2,     0,     0,     3,     4,     5,     6,     7,     8,     9,
      81,    84,    87,    90,     0,    10,     0,    42,    43,   162,
     164,    44,    11,     0,    54,    55,   101,    12,    56,    13,
      72,    73,    74,    40,    41,    42,    43,    91,   124,    44,
      45,    46,    47,    48,    49,     0,    50,     0,     0,     0,
     147,   150,   151,   152,   153,   154,   155,    40,    41,    42,
      43,     0,     0,    44,    45,    46,    47,    48,    49,     0,
      50,     0,     0,     0,    51,    72,    73,    74,    75,     0,
      52,    53,    54,    55,   163,   165,    56,    57,    58,    59,
      60,    61,     0,    62,     0,     0,     0,    63,    52,    53,
      54,    55,    92,     0,    56,    57,    58,    59,    60,    61,
       0,    62,    40,    41,    42,    43,     0,     0,    44,    45,
      46,    47,    48,    49,     0,    50,    52,    53,    54,    55,
       0,   159,    56,    57,    58,    59,    60,    61,    64,    62,
       0,    72,    73,    74,     0,    65,    66,    67,    68,    69,
       0,    70,     3,     4,     5,     0,    28,    29,    30,     0,
       0,     0,     0,     0,    36,   161,    53,    54,    55,    92,
       0,    56,    52,    53,    54,    55,     0,     0,    56,   160,
      41,    42,    43,     0,     0,    44,   161,    53,    54,    55,
       0,     0,    56
};

static const yytype_int16 yycheck[] =
{
       1,     3,     4,     5,    10,     7,     8,     9,    28,    10,
       3,     4,    13,    15,     7,     8,    11,    12,    13,    28,
      22,    16,    15,    24,    25,    26,    27,    15,    28,    35,
      10,    11,    12,    13,    35,    36,    16,    28,    27,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      27,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    27,    64,    10,     1,    72,    73,    74,    14,
      -1,    72,    73,    74,    10,    -1,    -1,    13,    -1,    24,
      25,    26,    11,    12,    13,    10,    -1,    16,    24,    25,
      26,    27,    17,    18,    19,    20,    21,    -1,    23,    35,
      36,    -1,    27,    -1,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,     1,    64,    10,
      11,    12,    13,    14,    -1,    16,    72,    73,    74,    13,
       0,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      24,    25,    26,    27,    -1,    15,    -1,    12,    13,   160,
     161,    16,    22,    -1,    12,    13,    40,    27,    16,    29,
      24,    25,    26,    10,    11,    12,    13,    14,    52,    16,
      17,    18,    19,    20,    21,    -1,    23,    -1,    -1,    -1,
      64,    65,    66,    67,    68,    69,    70,    10,    11,    12,
      13,    -1,    -1,    16,    17,    18,    19,    20,    21,    -1,
      23,    -1,    -1,    -1,    27,    24,    25,    26,    27,    -1,
      10,    11,    12,    13,   160,   161,    16,    17,    18,    19,
      20,    21,    -1,    23,    -1,    -1,    -1,    27,    10,    11,
      12,    13,    14,    -1,    16,    17,    18,    19,    20,    21,
      -1,    23,    10,    11,    12,    13,    -1,    -1,    16,    17,
      18,    19,    20,    21,    -1,    23,    10,    11,    12,    13,
      -1,    14,    16,    17,    18,    19,    20,    21,    10,    23,
      -1,    24,    25,    26,    -1,    17,    18,    19,    20,    21,
      -1,    23,     3,     4,     5,    -1,     7,     8,     9,    -1,
      -1,    -1,    -1,    -1,    15,    10,    11,    12,    13,    14,
      -1,    16,    10,    11,    12,    13,    -1,    -1,    16,    10,
      11,    12,    13,    -1,    -1,    16,    10,    11,    12,    13,
      -1,    -1,    16
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    31,     0,     3,     4,     5,     6,     7,     8,     9,
      15,    22,    27,    29,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    28,    28,    28,    28,     7,     8,
       9,    33,    34,    35,    36,    15,    15,    33,    34,    35,
      10,    11,    12,    13,    16,    17,    18,    19,    20,    21,
      23,    27,    10,    11,    12,    13,    16,    17,    18,    19,
      20,    21,    23,    27,    10,    17,    18,    19,    20,    21,
      23,    27,    24,    25,    26,    27,    27,    27,    27,    33,
      34,    35,    33,    34,    35,    33,    34,    35,    33,    34,
      35,    14,    14,    14,    33,    34,    36,    33,    34,    33,
      34,    35,    33,    34,    33,    34,    33,    34,    33,    34,
      33,    34,    33,    34,    33,    34,    33,    34,    33,    34,
      33,    34,    33,    34,    35,    33,    34,    33,    34,    33,
      34,    33,    34,    33,    34,    33,    34,    33,    34,    33,
      34,    33,    34,    33,    34,    33,    34,    35,    33,    34,
      35,    35,    35,    35,    35,    35,    36,    36,    36,    14,
      10,    10,    33,    34,    33,    34
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    30,    31,    31,    32,    32,    32,    32,    32,    32,
      32,    32,    33,    33,    33,    33,    33,    33,    33,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    35,    35,    35,
      35,    35,    35,    35,    36,    36,    36,    36,    36,    36,
      36,    37,    37,    37,    37,    37,    37,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    38,    38,    38,    38,
      38,    39,    39,    39,    40,    40,    40,    41,    41,    41,
      41,    41,    41,    41,    41,    41
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     1,     3,     3,     3,     3,     3,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     3,     1,
       3,     3,     3,     3,     1,     1,     3,     3,     3,     3,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:
#line 116 "a7bison.y" /* yacc.c:1646  */
    { printf("Result -> %d\n", (yyvsp[-1].integer));  }
#line 1470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 117 "a7bison.y" /* yacc.c:1646  */
    {printf("Result -> %lf\n", (yyvsp[-1].real));  }
#line 1476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 118 "a7bison.y" /* yacc.c:1646  */
    { printf("Result -> %s\n", (yyvsp[-1].string));  }
#line 1482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 119 "a7bison.y" /* yacc.c:1646  */
    {char *result; 
    					if((yyvsp[-1].string)=="TRUE") result="Left";
    					if((yyvsp[-1].string)=="FALSE") result="Right";
    					printf("Result -> %s\n", result); 
    				   }
#line 1492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 124 "a7bison.y" /* yacc.c:1646  */
    {printf("%s\n",(yyvsp[-1].string));}
#line 1498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 130 "a7bison.y" /* yacc.c:1646  */
    { (yyval.integer) = (yyvsp[-2].integer) + (yyvsp[0].integer); }
#line 1504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 131 "a7bison.y" /* yacc.c:1646  */
    { (yyval.integer) = (yyvsp[-2].integer) - (yyvsp[0].integer); }
#line 1510 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 132 "a7bison.y" /* yacc.c:1646  */
    {(yyval.integer) = (yyvsp[-2].integer)/(yyvsp[0].integer);}
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 133 "a7bison.y" /* yacc.c:1646  */
    {(yyval.integer) = (yyvsp[-2].integer) % (yyvsp[0].integer);}
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 134 "a7bison.y" /* yacc.c:1646  */
    {(yyval.integer)=(yyvsp[-1].integer);}
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 135 "a7bison.y" /* yacc.c:1646  */
    {	symrec *s;
    			s = getsym((yyvsp[0].string));
    			if(s!=0){
    				if(s->type == 'i'){
    					(yyval.integer) = atoi(s->data);
    				}
    			}
    		 }
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 145 "a7bison.y" /* yacc.c:1646  */
    {  (yyval.real) = (yyvsp[-2].real) + (yyvsp[0].real); }
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 146 "a7bison.y" /* yacc.c:1646  */
    { (yyval.real) = (yyvsp[-2].real) - (yyvsp[0].real); }
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 147 "a7bison.y" /* yacc.c:1646  */
    {  (yyval.real) = (double) (yyvsp[-2].integer) + (yyvsp[0].real); }
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 148 "a7bison.y" /* yacc.c:1646  */
    { (yyval.real) = (double) (yyvsp[-2].integer) - (yyvsp[0].real); }
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 149 "a7bison.y" /* yacc.c:1646  */
    {  (yyval.real) = (yyvsp[-2].real) + (double) (yyvsp[0].integer); }
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 150 "a7bison.y" /* yacc.c:1646  */
    { (yyval.real) = (yyvsp[-2].real) - (double) (yyvsp[0].integer); }
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 151 "a7bison.y" /* yacc.c:1646  */
    {(yyval.real) = (yyvsp[-2].real)/(yyvsp[0].real);}
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 152 "a7bison.y" /* yacc.c:1646  */
    {(yyval.real) = (yyvsp[-2].real) * (yyvsp[0].real);}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 153 "a7bison.y" /* yacc.c:1646  */
    {(yyval.real) = (yyvsp[-2].real) / (double) (yyvsp[0].integer);}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 154 "a7bison.y" /* yacc.c:1646  */
    {(yyval.real)= (yyvsp[-2].real) * (double) (yyvsp[0].integer);}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 155 "a7bison.y" /* yacc.c:1646  */
    {(yyval.real) = (double) (yyvsp[-2].integer) / (yyvsp[0].real);}
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 156 "a7bison.y" /* yacc.c:1646  */
    {(yyval.real) = (double) (yyvsp[-2].integer) * (yyvsp[0].real);}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 157 "a7bison.y" /* yacc.c:1646  */
    {(yyval.real) = (int)(yyvsp[-2].real) % (int)(yyvsp[0].real);}
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 158 "a7bison.y" /* yacc.c:1646  */
    {(yyval.real) = (int)(yyvsp[-2].real) % (yyvsp[0].integer);}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 159 "a7bison.y" /* yacc.c:1646  */
    {(yyval.real) =  (yyvsp[-2].integer) % (int)(yyvsp[0].real);}
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 160 "a7bison.y" /* yacc.c:1646  */
    {(yyval.real) =(yyvsp[-1].real);}
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 161 "a7bison.y" /* yacc.c:1646  */
    {	symrec *s;
    			s = getsym((yyvsp[0].string));
    			if(s!=0){
    				if(s->type == 'r'){
    					(yyval.real) = atof(s->data);
    				}
    			}
    		 }
#line 1650 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 171 "a7bison.y" /* yacc.c:1646  */
    { 		char * temp1 =malloc(sizeof(char)*(strlen((yyvsp[-2].string)))); 
								char * temp2 =malloc(sizeof(char)*(strlen((yyvsp[0].string))));
								sscanf((yyvsp[-2].string),"\"%s \"",temp1);
								temp1[strlen(temp1)-1] = 0;
								sscanf((yyvsp[0].string),"\"%s\"",temp2);
								temp2[strlen(temp2)-1] = 0;
								char* conString=malloc(sizeof(char)*(strlen(temp1)+strlen(temp2)+1));
                                strcpy(conString,temp1); 
                                strcat(conString,temp2);
                                (yyval.string)=conString;}
#line 1665 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 181 "a7bison.y" /* yacc.c:1646  */
    {symrec *s;
    			s = getsym((yyvsp[0].string));
    			if(s!=0){
    				if(s->type == 's'){
    					(yyval.string) = s->data;
    				}
    			}
    		   }
#line 1678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 189 "a7bison.y" /* yacc.c:1646  */
    {	char * temp1 =malloc(sizeof(char)*(strlen((yyvsp[-2].string))));
    					sscanf((yyvsp[-2].string),"\"%s \"",temp1);
						temp1[strlen(temp1)-1] = 0;
    					char temp[30];
    					sprintf(temp,"%d",(yyvsp[0].integer));
    					char* conString=malloc(sizeof(char)*(strlen((yyvsp[-2].string))+strlen(temp)+1));
    					strcpy(conString,temp1); 
                        strcat(conString,temp);
                        (yyval.string) = conString;
    				 }
#line 1693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 199 "a7bison.y" /* yacc.c:1646  */
    {	char * temp1 =malloc(sizeof(char)*(strlen((yyvsp[-2].string))));
    					sscanf((yyvsp[-2].string),"\"%s \"",temp1);
						temp1[strlen(temp1)-1] = 0;
    					char temp[30];
    					sprintf(temp,"%f",(yyvsp[0].real));
    					char* conString=malloc(sizeof(char)*(strlen((yyvsp[-2].string))+strlen(temp)+1));
    					strcpy(conString,temp1); 
                        strcat(conString,temp);
                        (yyval.string) = conString;
    				 }
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 209 "a7bison.y" /* yacc.c:1646  */
    {	char * temp1 =malloc(sizeof(char)*(strlen((yyvsp[0].string))));
    					sscanf((yyvsp[0].string),"\"%s \"",temp1);
						temp1[strlen(temp1)-1] = 0;
    					char temp[30];
    					sprintf(temp,"%d",(yyvsp[-2].integer));
    					char* conString=malloc(sizeof(char)*(strlen((yyvsp[0].string))+strlen(temp)+1));
    					strcpy(conString,temp); 
                        strcat(conString,temp1);
                        (yyval.string) = conString;
    				 }
#line 1723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 219 "a7bison.y" /* yacc.c:1646  */
    {	char * temp1 =malloc(sizeof(char)*(strlen((yyvsp[0].string))));
    					sscanf((yyvsp[0].string),"\"%s \"",temp1);
						temp1[strlen(temp1)-1] = 0;
    					char temp[30];
    					sprintf(temp,"%f",(yyvsp[-2].real));
    					char* conString=malloc(sizeof(char)*(strlen((yyvsp[0].string))+strlen(temp)+1));
    					strcpy(conString,temp); 
                        strcat(conString,temp1);
                        (yyval.string) = conString;
    				 }
#line 1738 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 232 "a7bison.y" /* yacc.c:1646  */
    {if((yyvsp[-2].string)=="TRUE"&&(yyvsp[0].string)=="TRUE") (yyval.string)="TRUE";
									else (yyval.string)="FALSE";
								   }
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 235 "a7bison.y" /* yacc.c:1646  */
    {if((yyvsp[-2].string)=="TRUE"||(yyvsp[0].string)=="TRUE") (yyval.string)="TRUE";
									else (yyval.string)="FALSE";
								   }
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 238 "a7bison.y" /* yacc.c:1646  */
    {if((yyvsp[-2].string)==(yyvsp[0].string))(yyval.string)="TRUE";
									else (yyval.string)="FALSE";
								   }
#line 1762 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 241 "a7bison.y" /* yacc.c:1646  */
    {(yyval.string)=(yyvsp[-1].string);}
#line 1768 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 242 "a7bison.y" /* yacc.c:1646  */
    {if((yyvsp[-1].string)=="TRUE") (yyval.string)="FALSE";
											else (yyval.string) ="TRUE";
										   }
#line 1776 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 246 "a7bison.y" /* yacc.c:1646  */
    {	char * temp1 =malloc(sizeof(char)*(strlen((yyvsp[-2].string)))); 
								char * temp2 =malloc(sizeof(char)*(strlen((yyvsp[0].string))));
								sscanf((yyvsp[-2].string),"\"%s \"",temp1);
								temp1[strlen(temp1)-1] = 0;
								sscanf((yyvsp[0].string),"\"%s\"",temp2);
								temp2[strlen(temp2)-1] = 0;
								if(strcmp(temp1,temp2)<0){(yyval.string)="TRUE";}
						   		else {(yyval.string) = "FALSE";}
					      }
#line 1790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 255 "a7bison.y" /* yacc.c:1646  */
    {	char * temp1 =malloc(sizeof(char)*(strlen((yyvsp[-2].string)))); 
								char * temp2 =malloc(sizeof(char)*(strlen((yyvsp[0].string))));
								sscanf((yyvsp[-2].string),"\"%s \"",temp1);
								temp1[strlen(temp1)-1] = 0;
								sscanf((yyvsp[0].string),"\"%s\"",temp2);
								temp2[strlen(temp2)-1] = 0;
								if(strcmp(temp1,temp2)>0){(yyval.string)="TRUE";}
						   		else {(yyval.string) = "FALSE";}
					      }
#line 1804 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 264 "a7bison.y" /* yacc.c:1646  */
    {	char * temp1 =malloc(sizeof(char)*(strlen((yyvsp[-2].string)))); 
									char * temp2 =malloc(sizeof(char)*(strlen((yyvsp[0].string))));
									sscanf((yyvsp[-2].string),"\"%s \"",temp1);
									temp1[strlen(temp1)-1] = 0;
									sscanf((yyvsp[0].string),"\"%s\"",temp2);
									temp2[strlen(temp2)-1] = 0;
									if(strcmp(temp1,temp2)<=0){(yyval.string)="TRUE";}
						   			else {(yyval.string) = "FALSE";}
					      }
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 273 "a7bison.y" /* yacc.c:1646  */
    {	char * temp1 =malloc(sizeof(char)*(strlen((yyvsp[-2].string)))); 
										char * temp2 =malloc(sizeof(char)*(strlen((yyvsp[0].string))));
										sscanf((yyvsp[-2].string),"\"%s \"",temp1);
										temp1[strlen(temp1)-1] = 0;
										sscanf((yyvsp[0].string),"\"%s\"",temp2);
										temp2[strlen(temp2)-1] = 0;
										if(strcmp(temp1,temp2)>=0){(yyval.string)="TRUE";}
						   				else {(yyval.string) = "FALSE";}
					      }
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 282 "a7bison.y" /* yacc.c:1646  */
    {	char * temp1 =malloc(sizeof(char)*(strlen((yyvsp[-2].string)))); 
								char * temp2 =malloc(sizeof(char)*(strlen((yyvsp[0].string))));
								sscanf((yyvsp[-2].string),"\"%s \"",temp1);
								temp1[strlen(temp1)-1] = 0;
								sscanf((yyvsp[0].string),"\"%s\"",temp2);
								temp2[strlen(temp2)-1] = 0;
								if(strcmp(temp1,temp2)==0){(yyval.string)="TRUE";}
							   	else {(yyval.string) = "FALSE";}
					      }
#line 1846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 291 "a7bison.y" /* yacc.c:1646  */
    {	char * temp1 =malloc(sizeof(char)*(strlen((yyvsp[-2].string)))); 
									char * temp2 =malloc(sizeof(char)*(strlen((yyvsp[0].string))));
									sscanf((yyvsp[-2].string),"\"%s \"",temp1);
									temp1[strlen(temp1)-1] = 0;
									sscanf((yyvsp[0].string),"\"%s\"",temp2);
									temp2[strlen(temp2)-1] = 0;	
									if(strcmp(temp1,temp2)!=0){(yyval.string)="TRUE";}
						   			else {(yyval.string) = "FALSE";}
					      }
#line 1860 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 302 "a7bison.y" /* yacc.c:1646  */
    {if((yyvsp[-2].real)<(yyvsp[0].real))(yyval.string)="TRUE";
							  else (yyval.string)="FALSE";	
							 }
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 305 "a7bison.y" /* yacc.c:1646  */
    {if((yyvsp[-2].integer)<(yyvsp[0].integer))(yyval.string)="TRUE";
							  else (yyval.string)="FALSE";	
							 }
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 308 "a7bison.y" /* yacc.c:1646  */
    {if((yyvsp[-2].real)<(yyvsp[0].integer))(yyval.string)="TRUE";
							  else (yyval.string)="FALSE";	
							 }
#line 1884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 311 "a7bison.y" /* yacc.c:1646  */
    {if((yyvsp[-2].integer)<(yyvsp[0].real))(yyval.string)="TRUE";
							  else (yyval.string)="FALSE";	
							 }
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 314 "a7bison.y" /* yacc.c:1646  */
    {if((yyvsp[-2].real)>(yyvsp[0].real))(yyval.string)="TRUE";
							  else (yyval.string)="FALSE";	
							 }
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 317 "a7bison.y" /* yacc.c:1646  */
    {if((yyvsp[-2].integer)>(yyvsp[0].integer))(yyval.string)="TRUE";
							  else (yyval.string)="FALSE";	
							 }
#line 1908 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 320 "a7bison.y" /* yacc.c:1646  */
    {if((yyvsp[-2].real)>(yyvsp[0].integer))(yyval.string)="TRUE";
							  else (yyval.string)="FALSE";	
							 }
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 323 "a7bison.y" /* yacc.c:1646  */
    {if((yyvsp[-2].integer)>(yyvsp[0].real))(yyval.string)="TRUE";
							  else (yyval.string)="FALSE";	
							 }
#line 1924 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 326 "a7bison.y" /* yacc.c:1646  */
    {if((yyvsp[-2].real)<=(yyvsp[0].real))(yyval.string)="TRUE";
							  else (yyval.string)="FALSE";	
							 }
#line 1932 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 329 "a7bison.y" /* yacc.c:1646  */
    {if((yyvsp[-2].integer)<=(yyvsp[0].integer))(yyval.string)="TRUE";
							  else (yyval.string)="FALSE";	
							 }
#line 1940 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 332 "a7bison.y" /* yacc.c:1646  */
    {if((yyvsp[-2].real)<=(yyvsp[0].integer))(yyval.string)="TRUE";
							  else (yyval.string)="FALSE";	
							 }
#line 1948 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 335 "a7bison.y" /* yacc.c:1646  */
    {if((yyvsp[-2].integer)<=(yyvsp[0].real))(yyval.string)="TRUE";
							  else (yyval.string)="FALSE";	
							 }
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 338 "a7bison.y" /* yacc.c:1646  */
    {if((yyvsp[-2].real)>=(yyvsp[0].real))(yyval.string)="TRUE";
							  else (yyval.string)="FALSE";	
							 }
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 341 "a7bison.y" /* yacc.c:1646  */
    {if((yyvsp[-2].integer)>=(yyvsp[0].integer))(yyval.string)="TRUE";
							  else (yyval.string)="FALSE";	
							 }
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 344 "a7bison.y" /* yacc.c:1646  */
    {if((yyvsp[-2].real)>=(yyvsp[0].integer))(yyval.string)="TRUE";
							  else (yyval.string)="FALSE";	
							 }
#line 1980 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 347 "a7bison.y" /* yacc.c:1646  */
    {if((yyvsp[-2].integer)>=(yyvsp[0].real))(yyval.string)="TRUE";
							  else (yyval.string)="FALSE";	
							 }
#line 1988 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 350 "a7bison.y" /* yacc.c:1646  */
    {if((yyvsp[-2].real)==(yyvsp[0].real))(yyval.string)="TRUE";
							  else (yyval.string)="FALSE";	
							 }
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 353 "a7bison.y" /* yacc.c:1646  */
    {if((yyvsp[-2].integer)==(yyvsp[0].integer))(yyval.string)="TRUE";
							  else (yyval.string)="FALSE";	
							 }
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 356 "a7bison.y" /* yacc.c:1646  */
    {if((yyvsp[-2].real)==(yyvsp[0].integer))(yyval.string)="TRUE";
							  else (yyval.string)="FALSE";	
							 }
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 359 "a7bison.y" /* yacc.c:1646  */
    {if((yyvsp[-2].integer)==(yyvsp[0].real))(yyval.string)="TRUE";
							  else (yyval.string)="FALSE";	
							 }
#line 2020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 362 "a7bison.y" /* yacc.c:1646  */
    {if((yyvsp[-2].real)!=(yyvsp[0].real))(yyval.string)="TRUE";
							  else (yyval.string)="FALSE";	
							 }
#line 2028 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 365 "a7bison.y" /* yacc.c:1646  */
    {if((yyvsp[-2].integer)!=(yyvsp[0].integer))(yyval.string)="TRUE";
							  else (yyval.string)="FALSE";	
							 }
#line 2036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 368 "a7bison.y" /* yacc.c:1646  */
    {if((yyvsp[-2].real)!=(yyvsp[0].integer))(yyval.string)="TRUE";
							  else (yyval.string)="FALSE";	
							 }
#line 2044 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 371 "a7bison.y" /* yacc.c:1646  */
    {if((yyvsp[-2].integer)!=(yyvsp[0].real))(yyval.string)="TRUE";
							  else (yyval.string)="FALSE";	
							 }
#line 2052 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 375 "a7bison.y" /* yacc.c:1646  */
    {char temp[10];
					sprintf(temp,"%f",(yyvsp[0].real));
					(yyval.string) = temp;}
#line 2060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 378 "a7bison.y" /* yacc.c:1646  */
    {char temp[10];
					sprintf(temp,"%d",(yyvsp[0].integer));
					(yyval.string) = temp;}
#line 2068 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 382 "a7bison.y" /* yacc.c:1646  */
    {(yyval.string) = (yyvsp[0].string);}
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 384 "a7bison.y" /* yacc.c:1646  */
    { 
				 				char * symname = (yyvsp[-2].string);
				 				char symdata[20];
				 				sprintf(symdata,"%d",(yyvsp[0].integer));
				 				install(symname,symdata,'i');
							   }
#line 2085 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 390 "a7bison.y" /* yacc.c:1646  */
    {	char * symname = (yyvsp[-2].string);
				 					char symdata[20];
				 					sprintf(symdata,"%f",(yyvsp[0].real));
				 					install(symname,symdata,'r');
				 				}
#line 2095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 395 "a7bison.y" /* yacc.c:1646  */
    {	char * symname = (yyvsp[-2].string);
				 					char symdata[50];
				 					strcpy(symdata, (yyvsp[0].string));
				 					install(symname,symdata,'s');
								}
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 401 "a7bison.y" /* yacc.c:1646  */
    { char * symname = (yyvsp[-2].string);
				 					char symdata[50];
				 					sprintf(symdata,"%d",(yyvsp[0].integer));
				 					install(symname,symdata,'i');
									}
#line 2115 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 406 "a7bison.y" /* yacc.c:1646  */
    { char * symname = (yyvsp[-2].string);
				 					char symdata[50];
				 					sprintf(symdata,"%f",(yyvsp[0].real));
				 					install(symname,symdata,'r');
									}
#line 2125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 411 "a7bison.y" /* yacc.c:1646  */
    { char * symname = (yyvsp[-2].string);
				 					char symdata[50];
				 					strcpy(symdata, (yyvsp[0].string));
				 					install(symname,symdata,'s');
									}
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 416 "a7bison.y" /* yacc.c:1646  */
    { char * symname = (yyvsp[-2].string);
				 					char symdata[50];
				 					sprintf(symdata,"%d",(yyvsp[0].integer));
				 					install(symname,symdata,'i');
									}
#line 2145 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 421 "a7bison.y" /* yacc.c:1646  */
    { char * symname = (yyvsp[-2].string);
				 					char symdata[50];
				 					sprintf(symdata,"%f",(yyvsp[0].real));
				 					install(symname,symdata,'r');
									}
#line 2155 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 426 "a7bison.y" /* yacc.c:1646  */
    { char * symname = (yyvsp[-2].string);
				 					char symdata[50];
				 					strcpy(symdata, (yyvsp[0].string));
				 					install(symname,symdata,'s');
									}
#line 2165 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 431 "a7bison.y" /* yacc.c:1646  */
    { char * symname = (yyvsp[-2].string);
				 					char symdata[50];
				 					sprintf(symdata,"%d",(yyvsp[0].integer));
				 					install(symname,symdata,'i');
									}
#line 2175 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 436 "a7bison.y" /* yacc.c:1646  */
    { char * symname = (yyvsp[-2].string);
				 					char symdata[50];
				 					sprintf(symdata,"%f",(yyvsp[0].real));
				 					install(symname,symdata,'r');

									}
#line 2186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 442 "a7bison.y" /* yacc.c:1646  */
    { char * symname = (yyvsp[-2].string);
				 					char symdata[50];
				 					strcpy(symdata, (yyvsp[0].string));
				 					install(symname,symdata,'s');
									}
#line 2196 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2200 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 447 "a7bison.y" /* yacc.c:1906  */

yyerror(char * str)
{
   fprintf(stderr, "%s\n", str);
}

