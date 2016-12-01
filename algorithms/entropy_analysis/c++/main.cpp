/*
	08/23/2016
	Make statistical analysis of vectors with different integer values, values of entropy and size. 
	Vectors values come from files in 'instance' folder to make a statistical file output.
*/
#include "sorting_algorithms.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

#define SAME_SIZE_VECTORS 5

const string INSTANCE_PATH = "//...//entropy_analysis//instancias//"; // FULL PATH here to access parent folder.
const string STATISTICAL_FILE_PATH = "results//statistic.txt";
//const string SORTED_PATH = "results//sorted_vectors//"; 

/*
	Runs one algorithm at a time accoding to parameter 'type'.

	@param path from file of the vector to be sorted.
	@param sortedLevel is the percentage of the vector already sorted.
	@param size of the vector.
	@param type is the choice of the algorithm.
	@param statisticalFile has the statistical data.
*/
void sortVectorFromFile(string path, int sortedLevel, int size, int type, std::ofstream& statisticalFile) {
	int v[size];
	clock_t begin, end;
	double elapsedSeconds; // Elapsed time to sort one vector.
	double averageSeconds = 0; // Average time to sort SAME_SIZE_VECTORS.

	for(int i=1; i<=SAME_SIZE_VECTORS; i++){
		// Open input vector file.
		ifstream inFile(path + to_string(sortedLevel) + "." + to_string(size) + "." + to_string(i) + ".in");

		for(int j=0; !inFile.eof(); j++){ // Reads vector from current file.
			inFile >> v[j];
		}
		inFile.close();

		begin = clock();
		switch(type){

			case 1: 
				insertion_sort(v, size);
				break;
			case 2:
				selection_sort(v, size);
				break;
			case 3:
				merge_sort(v, 0, size-1);
				break;
			case 4:
				quick_sort_last(v, 0, size);
				break;
			case 5:
				heapsort(v, size-1);
				break;
		}

		end = clock();
		elapsedSeconds = (double(end - begin) / CLOCKS_PER_SEC); // Elapsed time to sort current vector.

/*	
		// Writes current sorted vector.
		ofstream sortedFile(SORTED_PATH+ to_string(sortedLevel)+"."+ to_string(size)+"."+to_string(i)+"."+to_string(type)+".txt");
		for(int k=0; k<size-1; k++){
			sortedFile << v[k] << endl;
		}
		sortedFile.close();
*/		

		// Writes statistical data of the current vector.
		statisticalFile << "Algorithm " + to_string(type) + "; Vector " + to_string(i) + "; Sorted " + to_string(sortedLevel) + "\%; Size " + to_string(size) 
		+ "; Elapsed time "+ to_string(elapsedSeconds) +" secs"<< endl;
		averageSeconds += elapsedSeconds;
	}
	// Writes average elapsed time to run SAME_SIZE_VECTORS.
	averageSeconds /= SAME_SIZE_VECTORS;
	statisticalFile << "Average time: " + to_string(averageSeconds) + " secs\n" << endl;
}

/*
	Runs all test case from INSTANCE_PATH.
*/
int main(int argc, char* argv[]){

	int type = atoi(argv[2]); // Sorting type.	
	ofstream statisticalFile(STATISTICAL_FILE_PATH, ios::out);
	
	const int size1 = 100000;
	const int size2 = 500000;
	const int size3 = 1000000;
	const int sort1 = 10; // 10% sorted.
	const int sort2 = 50; // 50% sorted.
	const int sort3 = 90; // 90% sorted.

	sortVectorFromFile(INSTANCE_PATH, sort1, size1, type, statisticalFile);
	sortVectorFromFile(INSTANCE_PATH, sort1, size2, type, statisticalFile);
	sortVectorFromFile(INSTANCE_PATH, sort1, size3, type, statisticalFile);
	statisticalFile << "-----------------------------------------" << endl;

	sortVectorFromFile(INSTANCE_PATH, sort2, size1, type, statisticalFile);
	sortVectorFromFile(INSTANCE_PATH, sort2, size2, type, statisticalFile);
	sortVectorFromFile(INSTANCE_PATH, sort2, size3, type, statisticalFile);	
	statisticalFile << "-----------------------------------------" << endl;

	sortVectorFromFile(INSTANCE_PATH, sort3, size1, type, statisticalFile);
	sortVectorFromFile(INSTANCE_PATH, sort3, size2, type, statisticalFile);
	sortVectorFromFile(INSTANCE_PATH, sort3, size3, type, statisticalFile);

	return 0;
}