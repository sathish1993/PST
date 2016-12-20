all: program6.o list.o
	gcc program6.o list.o -o program6

program6.o:
	gcc -w -c program6.c -o program6.o

list.o:
	gcc -w -c list.c -o list.o

run:
	./program6

checkmem: all
	valgrind ./program6

clean:
	rm program6.o list.o program6
