all: main

dlinkList.o: dlinkList.h dlinkList.c
	gcc -Wall -ggdb -c dlinkList.c

main.o: main.c
	gcc -Wall -ggdb -c main.c

main: dlinkList.o main.o
	gcc -Wall -ggdb dlinkList.o main.o -o main

clean:
	rm *.o main

run:
	./main input.txt

run-memory:
	valgrind ./main input.txt
	
run-check:
	valgrind --leak-check=full ./main input.txt