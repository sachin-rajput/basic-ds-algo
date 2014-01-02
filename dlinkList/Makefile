all: main

dlinkList.o: dlinkList.h dlinkList.c
	gcc -c dlinkList.c

main.o: main.c
	gcc -c main.c

main: dlinkList.o main.o
	gcc dlinkList.o main.o -o main

clean:
	rm *.o main

run:
	./main input.txt

run-memory:
	valgrind ./main input.txt