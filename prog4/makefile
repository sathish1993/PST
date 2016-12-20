all: program4.o tournament.o
	gcc program4.o tournament.o -o program4 -lm

program4.o:
	gcc -w -c program4.c -o program4.o

tournament.o:
	gcc -c tournament.c -o tournament.o

run:
	./program4

checkmem: all
	valgrind ./program4

clean:
	rm program4.o tournament.o program4
