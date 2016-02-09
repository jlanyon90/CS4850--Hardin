exec : lex.yy.c y.tab.c
	gcc *.c -o a4_Lanyon

y.tab.c : a4bison.y
	yacc -d a4bison.y

lex.yy.c : a4grammer.l
	flex a4grammer.l

