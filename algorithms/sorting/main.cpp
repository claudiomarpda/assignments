/* 
--------------------------------------------------------------
05/08/2016
--------------------------------------------------------------
*/

#include "sorting_algorithms.h"
#include <stdio.h>
#include <iostream>

using namespace std;


int main(){

	cout << "1 - Insertion" << endl;
	cout << "2 - Selection" << endl;
	cout << "3 - Merge" << endl;
	cout << "4 - Quick" << endl;
	cout << "5 - Heap" << endl;
	cout << "Select the algorithm: " << endl;
	int type;
	cin >> type;

	int length;
	cin >> length; // Waits for the size of the vector.
	int values[length];

	for(int i=0; i<length; i++){
		cin >> values[i];
	}

	switch(type){

		case 1: 
			insertion_sort(values, length);
			break;
		case 2:
			selection_sort(values, length);
			break;
		case 3:
			merge_sort(values, 0, length-1);
			break;
		case 4:
			quick_sort_last(values, 0, length);
			break;
		case 5:
			heapsort(values, length-1);
			break;
	}

	cout << "\n -------  OUTPUT  -------  \n\n";

	// Prints vector after sorting.
	for(int i=0; i<length; i++){
		cout << values[i] << endl;
	}

	return 0;
}


