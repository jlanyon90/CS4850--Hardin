struct symrec
{
	char *name;
	char *data;
	char type;
	struct symrec *next;
};
typedef struct symrec symrec;
symrec *putsym(char * symname, char *symdata, char symtype);
symrec *getsym(char * symname);

struct ifrec
{
	char outcome [5];
	char instruct [2048];
	struct ifrec *next;
};
typedef struct ifrec ifrec;