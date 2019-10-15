all: lex.yy.o
	
lex.yy.o: lex.yy.c
	gcc -c lex.yy.c -o lex.yy.o	

lex.yy.c: parser.l
	flex parser.l

clean: 
	rm lex.yy.o -f

reset: 
	make clean 
