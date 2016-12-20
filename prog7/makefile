all: program7.o bst.o
	gcc program7.o bst.o -o program7

program6.o:
	gcc -w -c program7.c -o program7.o

list.o:
	gcc -w -c bst.c -o bst.o

run:
	./program7

checkmem: all
	valgrind ./program7

clean:
	rm program7.o bst.o program7
