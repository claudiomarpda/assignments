CC = g++ -std=c++11 -g -ggdb -Wextra

run: main.o list04.o
	$(CC) main.o list04.o ex04.o -o run

main.o: main.cpp
	$(CC) -c main.cpp

list04.o: list04.hpp list04.cpp ex04.hpp ex04.cpp
	$(CC) -c list04.cpp ex04.cpp

clean:
	rm *.o run