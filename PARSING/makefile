all: parser.exe

parser.exe: parser.o scanner.o
	gcc -o parser.exe parser.o scanner.o

scanner.o: lex.yy.c
	gcc -c lex.yy.c -o scanner.o

lex.yy.c:
	flex scanner.l  

parser.o: parser.tab.c
	gcc -c parser.tab.c -o parser.o

parser.tab.c: 
	bison -d parser.y

clean: 
	rm *.o -rf 
	rm *.c -rf
	rm *.h -rf
reset: 
	make clean && rm *.exe -rf
