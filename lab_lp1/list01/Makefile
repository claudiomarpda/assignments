CC = g++ -std=c++11

output: main.o list01.o
	$(CC) main.o list01.o -o output

main.o: main.cpp
	$(CC) -c main.cpp

list01.o: list01.hpp list01.cpp 
	$(CC) -c list01.cpp

clean:
	rm *.o output