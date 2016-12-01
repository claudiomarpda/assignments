#23/08/2016

CC = g++ -std=c++11 -O3

output: main.o sorting_algorithms.o
	$(CC) main.o sorting_algorithms.o -o output

main.o: main.cpp
	$(CC) -c main.cpp

sorting_algorithms.o: sorting_algorithms.h sorting_algorithms.cpp
	$(CC) -c sorting_algorithms.cpp

clean: 
	rm *.o output
	