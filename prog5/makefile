all: program5.o vector.o
	gcc program5.o vector.o -o program5

program5.o:
	gcc -w -c program5.c -o program5.o

vector.o:
	gcc -w -c vector.c -o vector.o

run:
	./program5

checkmem: all
	valgrind ./program5

clean:
	rm program5.o vector.o program5
