all: parser.exe

parser.exe: parser.o scanner.o cube.o
	gcc -o ../parser.exe parser.o scanner.o cube.o -L../mylib/ -ljedi

scanner.o: lex.yy.c
	gcc -c -g lex.yy.c -I ../mylib -o scanner.o

lex.yy.c:
	flex scanner.l 

parser.o: parser.tab.c
	gcc -c -g parser.tab.c -I../mylib -o parser.o 

parser.tab.c: 
	bison -dv parser.y 

cube.o: cube.c 
	gcc -c -g cube.c -I../mylib -o cube.o

clean: 
	rm parser.o scanner.o -rf 
	rm lex.yy.c parser.tab.c -rf
	rm parser.tab.h -rf
reset: 
	make clean && rm *.exe -rf
