
executable : y.tab.c lex.yy.c main.c
	gcc *.c -o a5_lanyon

y.tab.c : a5bison.y
	yacc -d a5bison.y

lex.yy.c : a5lex.l
	flex a5lex.l
clean : y.tab.c lex.yy.c y.tab.h a5_lanyon
	rm ./y.tab.c
	rm ./y.tab.h
	rm ./lex.yy.c
	rm ./a5_lanyon

