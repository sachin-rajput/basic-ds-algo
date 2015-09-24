all: main

tree.o: tree.h tree.c
	gcc -c tree.c

main.o: main.c
	gcc -c main.c

main: tree.o main.o
	gcc tree.o main.o -o main

clean:
	rm *.o main

run:
	./main input.txt

run-memory:
	valgrind ./main input.txt