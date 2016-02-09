CC = gcc
FILENAME = statemachine


${FILENAME}.exe: ${FILENAME}.c
	${CC} ${CFLAGS} -o ${FILENAME} ${FILENAME}.c

test : lex.yy.c a3flex.c
	gcc lex.yy.c a3flex.c -o test -lfl

lex.yy.c : lex.l
	flex lex.l
