LIB = ./mylib
LIBPATH = ./mylib/
GL = ./GL
GLEW = ./GL./GLEW
GLFW = ./GL./GLFW
REBUILDABLES = \
	       *.o \
	       *.stackdump
all: main.exe

main.exe: main.o jedi.a
	gcc main.o -o main.exe -L$(LIBPATH) -L$(GL) -L$(GLEW) -L$(GLFW) -ljedi -lopengl32 -lglew32 -lglfw3 -lgdi32

jedi.a: 
	cd $(LIB) && make

main.o: main.c 
	gcc -Wall -g -c -I$(LIB) -I$(GL) main.c -o main.o 

clean: 
	rm $(REBUILDABLES) -f
	cd $(LIB) && make clean && cd ..
	cd $(GLAD) && make clean && cd .. 
reset: 
	rm $(REBUILDABLES) main.exe -f
	cd $(LIB) && make reset && cd .. 
	cd $(GLAD) && make reset && cd ..
	
