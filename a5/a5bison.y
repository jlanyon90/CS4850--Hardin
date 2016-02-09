
%{
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
%}
%error-verbose
%union{
double real;
int integer;
char *string;
}

%token <integer> INT_TOKEN
%token <real> REAL_TOKEN
%token <string> STRING_TOKEN
%token PLUS
%token MINUS
%token DIVIDE
%token MULTIPLY
%token RPARENT
%token LPARENT
%token MOD
%token LESS
%token GREATER
%token LESS_EQUAL
%token GREATER_EQUAL
%token EQUAL
%token NOT_TOKEN
%token NOT_EQUAL
%token AND_TOKEN
%token OR_TOKEN
%token XOR_TOKEN
%token ENDOFLINE

%type <real> rexpr
%type <integer> iexpr
%type <string> sexpr
%type <string> compare
%type <string> strcompare
%type <string> numcompare
%left PLUS MINUS

%%
lines: 
     | lines line
;
line: iexpr ENDOFLINE{ printf("Result -> %d\n", $1);  } 
    | rexpr ENDOFLINE{printf("Result -> %lf\n", $1);  }
    | sexpr ENDOFLINE{ printf("Result -> %s\n", $1);  }
    | compare ENDOFLINE{printf("Result -> %s\n", $1); }
    | ENDOFLINE 
;
iexpr: INT_TOKEN
    | iexpr PLUS iexpr { $$ = $1 + $3; }
    | iexpr MINUS iexpr { $$ = $1 - $3; }
    | iexpr DIVIDE iexpr {$$ = $1/$3;}
    | iexpr MOD iexpr{$$ = $1 % $3;}
    | LPARENT iexpr RPARENT{$$=$2;}
;
rexpr: REAL_TOKEN 
    | rexpr PLUS rexpr {  $$ = $1 + $3; }
    | rexpr MINUS rexpr { $$ = $1 - $3; }
    | iexpr PLUS rexpr {  $$ = (double) $1 + $3; }
    | iexpr MINUS rexpr { $$ = (double) $1 - $3; }
    | rexpr PLUS iexpr {  $$ = $1 + (double) $3; }
    | rexpr MINUS iexpr { $$ = $1 - (double) $3; }
    | rexpr DIVIDE rexpr {$$ = $1/$3;}
    | rexpr MULTIPLY rexpr{$$ = $1 * $3;}
    | rexpr DIVIDE iexpr {$$ = $1 / (double) $3;}
    | rexpr MULTIPLY iexpr {$$= $1 * (double) $3;}
    | iexpr DIVIDE rexpr {$$ = (double) $1 / $3;}
    | iexpr MULTIPLY rexpr {$$ = (double) $1 * $3;}
    | rexpr MOD rexpr {$$ = (int)$1 % (int)$3;}
    | rexpr MOD iexpr {$$ = (int)$1 % $3;}
    | iexpr MOD rexpr {$$ =  $1 % (int)$3;}
    | LPARENT rexpr RPARENT{$$ =$2;}
;
sexpr: STRING_TOKEN
	| sexpr PLUS sexpr{ char* conString=malloc(sizeof(char)*(strlen($1)+strlen($3)+1));
                                strcpy(conString,$1); strcat(conString,$3);
                                $$=conString;}
;
compare: strcompare
		| numcompare
		| compare AND_TOKEN compare{if($1=="TRUE"&&$3=="TRUE") $$="TRUE";
									else $$="FALSE";
								   }
		| compare OR_TOKEN compare {if($1=="TRUE"||$3=="TRUE") $$="TRUE";
									else $$="FALSE";
								   }
		| compare XOR_TOKEN compare{if($1==$3)$$="TRUE";
									else $$="FALSE";
								   }
		| LPARENT compare RPARENT {$$=$2;}
		| NOT_TOKEN LPARENT compare RPARENT{if($3=="TRUE") $$="FALSE";
											else $$ ="TRUE";
										   }
;
strcompare: sexpr LESS sexpr {if(strcmp($1,$3)<0){$$="TRUE";}
						   else {$$ = "FALSE";}
					      }
		| sexpr GREATER sexpr {if(strcmp($1,$3)>0){$$="TRUE";}
						   else {$$ = "FALSE";}
					      }
		|sexpr LESS_EQUAL sexpr {if(strcmp($1,$3)<=0){$$="TRUE";}
						   else {$$ = "FALSE";}
					      }
		|sexpr GREATER_EQUAL sexpr {if(strcmp($1,$3)>=0){$$="TRUE";}
						   else {$$ = "FALSE";}
					      }
		|sexpr EQUAL sexpr {if(strcmp($1,$3)==0){$$="TRUE";}
						   else {$$ = "FALSE";}
					      }
		|sexpr NOT_EQUAL sexpr {if(strcmp($1,$3)!=0){$$="TRUE";}
						   else {$$ = "FALSE";}
					      }

;		
numcompare: rexpr LESS rexpr {if($1<$3)$$="TRUE";
							  else $$="FALSE";	
							 }
			|iexpr LESS iexpr{if($1<$3)$$="TRUE";
							  else $$="FALSE";	
							 }
			|rexpr LESS iexpr{if($1<$3)$$="TRUE";
							  else $$="FALSE";	
							 }
			|iexpr LESS rexpr{if($1<$3)$$="TRUE";
							  else $$="FALSE";	
							 }	
			|rexpr GREATER rexpr{if($1>$3)$$="TRUE";
							  else $$="FALSE";	
							 }
			|iexpr GREATER iexpr{if($1>$3)$$="TRUE";
							  else $$="FALSE";	
							 }
			|rexpr GREATER iexpr{if($1>$3)$$="TRUE";
							  else $$="FALSE";	
							 }
			|iexpr GREATER rexpr{if($1>$3)$$="TRUE";
							  else $$="FALSE";	
							 }
			|rexpr LESS_EQUAL rexpr{if($1<=$3)$$="TRUE";
							  else $$="FALSE";	
							 }
			|iexpr LESS_EQUAL iexpr{if($1<=$3)$$="TRUE";
							  else $$="FALSE";	
							 }
			|rexpr LESS_EQUAL iexpr{if($1<=$3)$$="TRUE";
							  else $$="FALSE";	
							 }
			|iexpr LESS_EQUAL rexpr{if($1<=$3)$$="TRUE";
							  else $$="FALSE";	
							 }
			|rexpr GREATER_EQUAL rexpr{if($1>=$3)$$="TRUE";
							  else $$="FALSE";	
							 }
			|iexpr GREATER_EQUAL iexpr{if($1>=$3)$$="TRUE";
							  else $$="FALSE";	
							 }
			|rexpr GREATER_EQUAL iexpr{if($1>=$3)$$="TRUE";
							  else $$="FALSE";	
							 }
			|iexpr GREATER_EQUAL rexpr{if($1>=$3)$$="TRUE";
							  else $$="FALSE";	
							 }	
			|rexpr EQUAL rexpr{if($1==$3)$$="TRUE";
							  else $$="FALSE";	
							 }
			|iexpr EQUAL iexpr{if($1==$3)$$="TRUE";
							  else $$="FALSE";	
							 }
			|rexpr EQUAL iexpr{if($1==$3)$$="TRUE";
							  else $$="FALSE";	
							 }
			|iexpr EQUAL rexpr{if($1==$3)$$="TRUE";
							  else $$="FALSE";	
							 }	
			|rexpr NOT_EQUAL rexpr{if($1!=$3)$$="TRUE";
							  else $$="FALSE";	
							 }
			|iexpr NOT_EQUAL iexpr{if($1!=$3)$$="TRUE";
							  else $$="FALSE";	
							 }
			|rexpr NOT_EQUAL iexpr{if($1!=$3)$$="TRUE";
							  else $$="FALSE";	
							 }
			|iexpr NOT_EQUAL rexpr{if($1!=$3)$$="TRUE";
							  else $$="FALSE";	
							 }			   
;
%%
yyerror(char * str)
{
   fprintf(stderr, "%s\n", str);
}

