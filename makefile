LIB = ./mylib
LIBPATH = ./mylib/
REBUILDABLES = \
	       *.o \
	       *.stackdump
all: main.exe

main.exe: main.o mylib.a
	gcc -o main.exe main.o $(LIBPATH)mylib.a

mylib.a: 
	cd $(LIB) && make

main.o: main.c 
	gcc -Wall -g -c -I $(LIB) main.c -o main.o 

clean: 
	rm $(REBUILDABLES) -f
	cd $(LIB) && make clean 
reset: 
	rm $(REBUILDABLES) main.exe -f
	cd $(LIB) && make reset 
	
