#CC = g++ -std=c++11
CC = gcc -std=c99

run: main.o list02.o
	$(CC) main.o list02.o -o run

main.o: main.c
	$(CC) -c main.c

list01.o: list02.h list02.c 
	$(CC) -c list02.c

clean:
	rm *.o run