LIB = ./mylib
LIBPATH = ./mylib/
PARS = ./PARSING/
GL = ./GL
GLEW = ./GL./GLEW
GLFW = ./GL./GLFW
REBUILDABLES = \
	       *.o \
	       *.stackdump
all: main.exe

main.exe: main.o jedi.a $(PARS)lex.yy.o
	gcc main.o $(PARS)lex.yy.o -o main.exe -L$(LIBPATH) -L$(GL) -L$(GLEW) -L$(GLFW) -ljedi -lopengl32 -lglew32 -lglfw3 -lgdi32

jedi.a: 
	cd $(LIB) && make

$(PARS)lex.yy.o:
	cd ./PARSING && make

main.o: main.c 
	gcc -Wall -g -c -I$(LIB) -I$(GL) -I$(PARS) main.c -o main.o 

clean: 
	rm $(REBUILDABLES) -f
	cd $(LIB) && make clean && cd ..
reset: 
	rm $(REBUILDABLES) main.exe -f
	cd $(LIB) && make reset && cd .. 
	
