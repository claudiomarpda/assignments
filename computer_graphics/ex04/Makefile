CC = gcc -g -ggdb -Wextra

run: main.o
	$(CC) main.o -o run

main.o: main.c
	$(CC) -c main.c

clean:
	rm *.o run cpy_cube.x3d