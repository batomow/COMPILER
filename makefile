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

#main.exe: main.o jedi.a
#	gcc main.o -o main.exe -L$(LIBPATH) -L$(GL) -L$(GLEW) -L$(GLFW) -ljedi -lopengl32 -lglew32 -lglfw3 -lgdi32
main.exe: main.o jedi.a
	gcc main.o -o main.exe -L$(LIBPATH) -ljedi

jedi.a: 
	cd $(LIB) && make && cd .$(PARS) && make

main.o: main.c 
	gcc -Wall -Werror -g -c -I$(LIB) -I$(GL) -I$(PARS) main.c -o main.o 

clean: 
	rm $(REBUILDABLES) -f
	cd $(LIB) && make clean && cd ..
	cd $(PARS) && make clean && cd .. 
reset: 
	rm $(REBUILDABLES) main.exe -f
	cd $(LIB) && make reset && cd .. 
	cd $(PARS) && make reset && cd .. 
	
