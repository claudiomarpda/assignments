#CC = g++ -std=c++11
CC = gcc

run: main.o list02.o
	$(CC) main.o list02.o -o run

main.o: main.cpp
	$(CC) -c main.cpp

list01.o: list02.hpp list02.cpp 
	$(CC) -c list02.cpp

clean:
	rm *.o run