all: main

dlinkList.o: dlinkList.h dlinkList.c
	gcc -Wall -ggdb -c dlinkList.c
	
queue.o: queue.h queue.c
	gcc -Wall -ggdb -c queue.c

main.o: main.c
	gcc -Wall -ggdb -c main.c

main: dlinkList.o queue.o main.o
	gcc -Wall -ggdb dlinkList.o queue.o main.o -o main

clean:
	rm *.o main

run:
	./main input.txt

run-memory:
	valgrind ./main input.txt
	
run-check:
	valgrind --leak-check=full ./main input.txt