executable : y.tab.c lex.yy.c main.c
	gcc *.c -Wall -o a6_lanyon

y.tab.c : a6bison.y
	yacc -d a6bison.y

lex.yy.c : a6lex.l
	flex a6lex.l

clean : y.tab.c lex.yy.c y.tab.h a6_lanyon
	rm ./y.tab.c
	rm ./y.tab.h
	rm ./lex.yy.c
	rm ./a6_lanyon

