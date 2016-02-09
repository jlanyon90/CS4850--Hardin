
//extern int yyparse();
   // yyparse();


 //Assumption —primary operators ‘-,+,*,/,%’ operand — a single digit
#include <stdio.h>
extern int yyparse();

#define MAX 20
typedef struct stack
{
	int data[MAX];
	int top;
}stack;
char string[100] ="";
/* PROTOTYPES*/
void init(stack *);
int empty(stack *);
int full(stack *);
int pop(stack *);
void push(stack *,int);
int evaluate(char x,int op1,int op2);


void main()
{
	stack s;
	char x;
    int i=0;
	int op1,op2,val;
	init(&s);
	printf("Enter the expression(eg:59+3*)nSingle digit operand and operators only:");
    yyparse();
	while(i<strlen(string))
	{
        x = string[i];
		if(isdigit(x))
                push(&s,x-48);      //x-48 for removing the effect of ASCII
        else{
            	op2=pop(&s);
            	op1=pop(&s);
            	val=evaluate(x,op1,op2);
            	push(&s,val);
            }
        i++;
    }
        val=pop(&s);
        printf("nValue of expression=%d\n",val);
    }
int evaluate(char x,int op1,int op2)
    {
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
    }
    void init(stack *s)
    {
    	s->top=-1;
    }
    int empty(stack *s)
    {
    	if(s->top==-1)
    		return(1);
    	return(0);
    }
    int full(stack *s)
    {
    	if(s->top==MAX-1)
    		return(1);
    	return(0);
    }
    void push(stack *s,int x)
    {
    	s->top=s->top+1;
    	s->data[s->top]=x;
    }
    int pop(stack *s)
    {
    	int x;
    	x=s->data[s->top];
    	s->top=s->top-1;
    	return(x);
    }
    void getstring(char * sentString){
        strcpy(string,sentString);
    }