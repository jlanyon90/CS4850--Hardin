CC = gcc
CFLAGS = -ansi -pedantic -Wall

all: main lex.yy.c
main:	main.c lex.yy.c y.tab.h
	${CC} ${CFLAGS} -o a3_lanyon main.c lex.yy.c
lex.yy.c: myLex.l
	flex myLex.l
clean:
	rm -f lex.yy.c main
