OBJECTS = stack.o var.o queue.o 

all: mylib.a

mylib.a: $(OBJECTS)
	ar rsv mylib.a $(OBJECTS) 

%.o: %.c
	gcc -Wall -g -c $< -o $@

clean: 
	rm *.o -f

reset: 
	rm *.o mylib.a -f
