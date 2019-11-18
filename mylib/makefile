
OBJECTS = stack.o var.o queue.o map.o vartable.o

all: libjedi.a

libjedi.a: $(OBJECTS)
	ar rsv libjedi.a $(OBJECTS) 

%.o: %.c
	gcc -Wall -g -c $< -o $@ 

clean: 
	rm *.o -f

reset: 
	rm *.o *.a -f
