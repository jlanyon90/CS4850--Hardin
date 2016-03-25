A4 - Postfix calculator

Assignment specs are given in A4assignment.docx

This is first assignment with both Bison and Flex. You input a equation with single digit operands say (1+3-2) and it returns the postfix version of that expression (13+2-) as well as the answer to the expression.



To Run
1.) make y.tab.c -creates y.tab.c file
2.) make lex.yy.c - creates lex.yy.c file
3.) make exec -creates a4_lanyon executable file
4.) ./a4_Lanyon - runs program until EOF (Ctrl+D)