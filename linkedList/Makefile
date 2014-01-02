all: main

linkedList.o: linkedList.h linkedList.c
	gcc -c linkedList.c

main.o: main.c
	gcc -c main.c

main: linkedList.o main.o
	gcc linkedList.o main.o -o main

clean:
	rm *.o main

run:
	./main input.txt

run-memory:
	valgrind ./main input.txt