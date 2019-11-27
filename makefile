LIB = ./mylib
LIBPATH = ./mylib/
PARS = ./parsing/
REBUILDABLES = \
	       *.o \
	       *.stackdump\
	       *.fso

all: main.fso

main.fso: jedi.a
	./parser.exe > ./vm/main.fso && make clean 

jedi.a: 
	make reset && cd $(LIB) && make && cd .$(PARS) && make

clean: 
	rm $(REBUILDABLES) -f
	cd $(LIB) && make clean && cd ..
	cd $(PARS) && make clean && cd .. 

reset: 
	rm $(REBUILDABLES) main.exe parser.exe -f
	cd $(LIB) && make reset && cd .. 
	cd $(PARS) && make reset && cd .. 
	cd ./vm && make reset && cd .. 
	
