all : program2.o
	gcc -o project2 program2.o

program2.o: program2.c
	gcc -c program2.c -o program2.o

checkmem:
	valgrind ./project2

defuseTheBomb:	bomb.o defuseMe.o
	gcc -g -o defuseTheBomb bomb.c defuseMe.c hidden.o

bomb.o:	bomb.c
	gcc -g -c bomb.c -o bomb.o 

defuseMe.o : defuseMe.c
	gcc -g -c defuseMe.c -o defuseMe.o

clean:
	rm -- !(hidden.o) defuseTheBomb project2
