
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
%token <string> SYMBOL
%token <string> ISYMBOL
%token <string> RSYMBOL
%token <string> STRSYMBOL
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
%token ASSIGNMENT
%token HONK

%type <real> rexpr
%type <integer> iexpr
%type <string> sexpr
%type <string> compare
%type <string> strcompare
%type <string> numcompare
%type <string> printer
%left PLUS MINUS

%%
lines: 
     | lines line
;
line: iexpr ENDOFLINE{ printf("Result -> %d\n", $1);  } 
    | rexpr ENDOFLINE{printf("Result -> %lf\n", $1);  }
    | sexpr ENDOFLINE{ printf("Result -> %s\n", $1);  }
    | compare ENDOFLINE{char *result; 
    					if($1=="TRUE") result="Left";
    					if($1=="FALSE") result="Right";
    					printf("Result -> %s\n", result); 
    				   }
    | printer ENDOFLINE{printf("%s\n",$1);}
    | assign ENDOFLINE
    | reassign ENDOFLINE
    | ENDOFLINE 
;
iexpr: INT_TOKEN
    | iexpr PLUS iexpr { $$ = $1 + $3; }
    | iexpr MINUS iexpr { $$ = $1 - $3; }
    | iexpr DIVIDE iexpr {$$ = $1/$3;}
    | iexpr MOD iexpr{$$ = $1 % $3;}
    | LPARENT iexpr RPARENT{$$=$2;}
    | ISYMBOL {	symrec *s;
    			s = getsym($1);
    			if(s!=0){
    				if(s->type == 'i'){
    					$$ = atoi(s->data);
    				}
    			}
    		 }
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
    | RSYMBOL {	symrec *s;
    			s = getsym($1);
    			if(s!=0){
    				if(s->type == 'r'){
    					$$ = atof(s->data);
    				}
    			}
    		 }
;
sexpr: STRING_TOKEN
	| sexpr PLUS sexpr{ 		char * temp1 =malloc(sizeof(char)*(strlen($1))); 
								char * temp2 =malloc(sizeof(char)*(strlen($3)));
								sscanf($1,"\"%s \"",temp1);
								temp1[strlen(temp1)-1] = 0;
								sscanf($3,"\"%s\"",temp2);
								temp2[strlen(temp2)-1] = 0;
								char* conString=malloc(sizeof(char)*(strlen(temp1)+strlen(temp2)+1));
                                strcpy(conString,temp1); 
                                strcat(conString,temp2);
                                $$=conString;}
    | STRSYMBOL{symrec *s;
    			s = getsym($1);
    			if(s!=0){
    				if(s->type == 's'){
    					$$ = s->data;
    				}
    			}
    		   } 
    |sexpr PLUS iexpr{	char * temp1 =malloc(sizeof(char)*(strlen($1)));
    					sscanf($1,"\"%s \"",temp1);
						temp1[strlen(temp1)-1] = 0;
    					char temp[30];
    					sprintf(temp,"%d",$3);
    					char* conString=malloc(sizeof(char)*(strlen($1)+strlen(temp)+1));
    					strcpy(conString,temp1); 
                        strcat(conString,temp);
                        $$ = conString;
    				 }
    |sexpr PLUS rexpr{	char * temp1 =malloc(sizeof(char)*(strlen($1)));
    					sscanf($1,"\"%s \"",temp1);
						temp1[strlen(temp1)-1] = 0;
    					char temp[30];
    					sprintf(temp,"%f",$3);
    					char* conString=malloc(sizeof(char)*(strlen($1)+strlen(temp)+1));
    					strcpy(conString,temp1); 
                        strcat(conString,temp);
                        $$ = conString;
    				 }
    |iexpr PLUS sexpr{	char * temp1 =malloc(sizeof(char)*(strlen($3)));
    					sscanf($3,"\"%s \"",temp1);
						temp1[strlen(temp1)-1] = 0;
    					char temp[30];
    					sprintf(temp,"%d",$1);
    					char* conString=malloc(sizeof(char)*(strlen($3)+strlen(temp)+1));
    					strcpy(conString,temp); 
                        strcat(conString,temp1);
                        $$ = conString;
    				 }
    |rexpr PLUS sexpr{	char * temp1 =malloc(sizeof(char)*(strlen($3)));
    					sscanf($3,"\"%s \"",temp1);
						temp1[strlen(temp1)-1] = 0;
    					char temp[30];
    					sprintf(temp,"%f",$1);
    					char* conString=malloc(sizeof(char)*(strlen($3)+strlen(temp)+1));
    					strcpy(conString,temp); 
                        strcat(conString,temp1);
                        $$ = conString;
    				 }
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
strcompare: sexpr LESS sexpr {	char * temp1 =malloc(sizeof(char)*(strlen($1))); 
								char * temp2 =malloc(sizeof(char)*(strlen($3)));
								sscanf($1,"\"%s \"",temp1);
								temp1[strlen(temp1)-1] = 0;
								sscanf($3,"\"%s\"",temp2);
								temp2[strlen(temp2)-1] = 0;
								if(strcmp(temp1,temp2)<0){$$="TRUE";}
						   		else {$$ = "FALSE";}
					      }
		| sexpr GREATER sexpr {	char * temp1 =malloc(sizeof(char)*(strlen($1))); 
								char * temp2 =malloc(sizeof(char)*(strlen($3)));
								sscanf($1,"\"%s \"",temp1);
								temp1[strlen(temp1)-1] = 0;
								sscanf($3,"\"%s\"",temp2);
								temp2[strlen(temp2)-1] = 0;
								if(strcmp(temp1,temp2)>0){$$="TRUE";}
						   		else {$$ = "FALSE";}
					      }
		|sexpr LESS_EQUAL sexpr {	char * temp1 =malloc(sizeof(char)*(strlen($1))); 
									char * temp2 =malloc(sizeof(char)*(strlen($3)));
									sscanf($1,"\"%s \"",temp1);
									temp1[strlen(temp1)-1] = 0;
									sscanf($3,"\"%s\"",temp2);
									temp2[strlen(temp2)-1] = 0;
									if(strcmp(temp1,temp2)<=0){$$="TRUE";}
						   			else {$$ = "FALSE";}
					      }
		|sexpr GREATER_EQUAL sexpr {	char * temp1 =malloc(sizeof(char)*(strlen($1))); 
										char * temp2 =malloc(sizeof(char)*(strlen($3)));
										sscanf($1,"\"%s \"",temp1);
										temp1[strlen(temp1)-1] = 0;
										sscanf($3,"\"%s\"",temp2);
										temp2[strlen(temp2)-1] = 0;
										if(strcmp(temp1,temp2)>=0){$$="TRUE";}
						   				else {$$ = "FALSE";}
					      }
		|sexpr EQUAL sexpr {	char * temp1 =malloc(sizeof(char)*(strlen($1))); 
								char * temp2 =malloc(sizeof(char)*(strlen($3)));
								sscanf($1,"\"%s \"",temp1);
								temp1[strlen(temp1)-1] = 0;
								sscanf($3,"\"%s\"",temp2);
								temp2[strlen(temp2)-1] = 0;
								if(strcmp(temp1,temp2)==0){$$="TRUE";}
							   	else {$$ = "FALSE";}
					      }
		|sexpr NOT_EQUAL sexpr {	char * temp1 =malloc(sizeof(char)*(strlen($1))); 
									char * temp2 =malloc(sizeof(char)*(strlen($3)));
									sscanf($1,"\"%s \"",temp1);
									temp1[strlen(temp1)-1] = 0;
									sscanf($3,"\"%s\"",temp2);
									temp2[strlen(temp2)-1] = 0;	
									if(strcmp(temp1,temp2)!=0){$$="TRUE";}
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
printer: HONK rexpr{char temp[10];
					sprintf(temp,"%f",$2);
					$$ = temp;}
		 |HONK iexpr{char temp[10];
					sprintf(temp,"%d",$2);
					$$ = temp;}
		 
		 |HONK sexpr{$$ = $2;}		 			
;
assign: SYMBOL ASSIGNMENT iexpr{ 
				 				char * symname = $1;
				 				char symdata[20];
				 				sprintf(symdata,"%d",$3);
				 				install(symname,symdata,'i');
							   }
		|SYMBOL ASSIGNMENT rexpr{	char * symname = $1;
				 					char symdata[20];
				 					sprintf(symdata,"%f",$3);
				 					install(symname,symdata,'r');
				 				}
		|SYMBOL ASSIGNMENT sexpr{	char * symname = $1;
				 					char symdata[50];
				 					strcpy(symdata, $3);
				 					install(symname,symdata,'s');
								}
;
reassign: STRSYMBOL ASSIGNMENT iexpr{ char * symname = $1;
				 					char symdata[50];
				 					sprintf(symdata,"%d",$3);
				 					install(symname,symdata,'i');
									}
		  |STRSYMBOL ASSIGNMENT rexpr{ char * symname = $1;
				 					char symdata[50];
				 					sprintf(symdata,"%f",$3);
				 					install(symname,symdata,'r');
									}
		  |STRSYMBOL ASSIGNMENT sexpr{ char * symname = $1;
				 					char symdata[50];
				 					strcpy(symdata, $3);
				 					install(symname,symdata,'s');
									}
		  |ISYMBOL ASSIGNMENT iexpr{ char * symname = $1;
				 					char symdata[50];
				 					sprintf(symdata,"%d",$3);
				 					install(symname,symdata,'i');
									}
		  |ISYMBOL ASSIGNMENT rexpr{ char * symname = $1;
				 					char symdata[50];
				 					sprintf(symdata,"%f",$3);
				 					install(symname,symdata,'r');
									}
		  |ISYMBOL ASSIGNMENT sexpr{ char * symname = $1;
				 					char symdata[50];
				 					strcpy(symdata, $3);
				 					install(symname,symdata,'s');
									}
		  |RSYMBOL ASSIGNMENT iexpr{ char * symname = $1;
				 					char symdata[50];
				 					sprintf(symdata,"%d",$3);
				 					install(symname,symdata,'i');
									}
		  |RSYMBOL ASSIGNMENT rexpr{ char * symname = $1;
				 					char symdata[50];
				 					sprintf(symdata,"%f",$3);
				 					install(symname,symdata,'r');

									}
		  |RSYMBOL ASSIGNMENT sexpr{ char * symname = $1;
				 					char symdata[50];
				 					strcpy(symdata, $3);
				 					install(symname,symdata,'s');
									};
%%
yyerror(char * str)
{
   fprintf(stderr, "%s\n", str);
}

