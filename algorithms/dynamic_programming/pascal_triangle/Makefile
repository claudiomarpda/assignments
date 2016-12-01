#23/08/2016

CC = g++ -std=c++11

output: pascal_triangle.o
	$(CC) pascal_triangle.o -o output

main.o: pascal_triangle.cpp
	$(CC) -c pascal_triangle.cpp

clean: 
	rm *.o output
	