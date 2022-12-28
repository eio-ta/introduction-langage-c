all : main

main : main.o code.o
	gcc -Wall -o main main.o code.o

main.o : main.c code.h
	gcc -Wall -c main.c
	
code.o : main.c code.h
	gcc -Wall -c code.c

clean :
	rm *.o
