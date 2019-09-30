OBJECTS = stack.o var.o queue.o leak_detector.o
all: mylib.a

mylib.a: $(OBJECTS)
	ar rsv mylib.a $(OBJECTS) 

%.o: %.c
	gcc -Wall -g -c $< -o $@

clean: 
	rm *.o -f
	cd ./leak_detector && make clean

reset: 
	rm *.o mylib.a -f
	cd ./leak_detector && make reset
