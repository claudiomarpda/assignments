CC = gcc -std=c99 -g -ggdb -Wextra

run: main.o list03.o ex04.o ex05.o ex06.o
	$(CC) main.o list03.o ex04.o ex05.o ex06.o -o run

main.o: main.c
	$(CC) -c main.c

list03.o: list03.h list03.c ex04.h ex04.c ex05.h ex05.c ex06.h ex06.c
	$(CC) -c list03.c ex04.c ex05.c

clean:
	rm *.o run