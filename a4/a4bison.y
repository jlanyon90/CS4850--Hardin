%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>
    #include <string.h>
    extern int yywrap();
    char string[100];
    int counter=0;
    void getstring(char * string);
%}
%union{
    char character;
    int integer;
};

%token <integer> NUM
%token ENDOFLINE
%left '+' '-'
%left '*' '/'
%right NEGATIVE

%%

State:  Exp{printf("\n");}
    ;
Exp:  Exp '+' Exp {printf("+"); 
				   string[counter]='+';
				   counter++;
				  }
    |   Exp '*' Exp {printf("*");
    			   string[counter]='*';
    			   counter++;
    			  }
    |   Exp '-' Exp {printf("-");
    				 string[counter]='-';
    				 counter++;
    				}
    |   Exp '/' Exp {printf("/");
    				 string[counter]='/';
    				 counter++;
    				}
    |   '(' Exp ')'
    |   '-' Exp %prec NEGATIVE {printf("-");
    							string[counter]='-';
    							counter++;
    						   }
    |   NUM     {printf("%d", yylval.integer);
    			 string[counter]=yylval.integer +'0';
    			 counter++;
    			}
    ;
%%


#define MAX 20
typedef struct stack
{
	int data[MAX];
	int top;
}stack;

/* PROTOTYPES*/
void initialize(stack *);
int empty(stack *);
int full(stack *);
int pop(stack *);
void push(stack *,int);
int evaluate(char x,int op1,int op2);


void main(){
	stack s;
	char x;
    int i=0;
	int op1,op2,val;
	initialize(&s);
	while(!feof(stdin)){
		printf("Enter the expression single digit operand and operators only:");
    	yyparse();
    	if(!feof(stdin)){
			while(i<strlen(string))
			{
	        	x = string[i];
				if(isdigit(x))
                	push(&s,x-48);
        		else{
            		op2=pop(&s);
            		op1=pop(&s);
            		val=evaluate(x,op1,op2);
	            	push(&s,val);
            	}
	        	i++;
    		}
        	val=pop(&s);
        	printf("\nValue of expression=%d\n",val);
		}
    }
       printf("Thank you!\n");
 }/*END OF MAIN*/

int evaluate(char x,int op1,int op2){
    	if(x=='+')
    		return(op1+op2);
    	if(x=='-')
    		return(op1-op2);
    	if(x=='*')
    		return(op1*op2);
    	if(x=='/')
    		return(op1/op2);
    	if(x=='%')
    		return(op1%op2);
    }/*END OF EVALUATE*/

void initialize(stack *s){
    	s->top=-1;
    }/*END OF INITIALIZE*/

int empty(stack *s){
    	if(s->top==-1)
    		return(1);
    	return(0);
    }/*END OF EMPTY*/

int full(stack *s){
    	if(s->top==MAX-1)
    		return(1);
    	return(0);
    }/*END OF FULL*/

void push(stack *s,int x){
    	s->top=s->top+1;
    	s->data[s->top]=x;
    }/*END OF PUSH*/

int pop(stack *s){
    	int x;
    	x=s->data[s->top];
    	s->top=s->top-1;
    	return(x);
    }/*END OF POP*/


int yyerror (char *msg) {
    return 0;
}
