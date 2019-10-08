OBJECTS = stack.o var.o queue.o
all: libjedi.a

libjedi.a: $(OBJECTS)
	ar rsv libjedi.a $(OBJECTS) 

%.o: %.c
	gcc -Wall -g -c $< -o $@

clean: 
	rm *.o -f
	cd ./leak_detector && make clean

reset: 
	rm *.o *.a -f
	cd ./leak_detector && make reset
