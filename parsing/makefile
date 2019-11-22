all: parser.exe

parser.exe: parser.o scanner.o
	gcc -o ../parser.exe parser.o scanner.o -L../mylib/ -ljedi

scanner.o: lex.yy.c
	gcc -c lex.yy.c -I ../mylib -o scanner.o

lex.yy.c:
	flex scanner.l 

parser.o: parser.tab.c
	gcc -c parser.tab.c -I../mylib -o parser.o 

parser.tab.c: 
	bison -d parser.y 

clean: 
	rm parser.o scanner.o -rf 
	rm lex.yy.c parser.tab.c -rf
	rm parser.tab.h -rf
reset: 
	make clean && rm *.exe -rf
