executable : y.tab.c lex.yy.c main.c
	gcc *.c -o a7_lanyon

y.tab.c : a7bison.y
	yacc -d a7bison.y

lex.yy.c : a7lex.l
	flex a7lex.l

clean : y.tab.c lex.yy.c y.tab.h a7_lanyon
	rm ./y.tab.c
	rm ./y.tab.h
	rm ./lex.yy.c
	rm ./a7_lanyon

