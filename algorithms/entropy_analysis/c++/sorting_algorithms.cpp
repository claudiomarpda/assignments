/* 
05/08/2016

Usual parameters:
	@param v[] is the array to be sorted
	@param length is the number of elements
*/


#include "sorting_algorithms.h"

using namespace std;

/*
	Shifts elements to the left while its value 
	is larger than the left element.
*/

void insertion_sort(int v[], int length){
	int i, j, key;

	for(j=1; j<length; j++){
		key = v[j];
		i = j-1;

		while(i>=0 && v[i]>key){
			v[i+1] = v[i];
			i--;
		}
		v[i+1] = key;
	}
}

/* 
	Searches for the minimum value and put it in sorted
	order, keeping the loop invariant.
*/
void selection_sort(int v[], int length){
	int i,j, min;
	int key;

	for(i=0; i < length-1; i++){
		min = i;
		for(j=i+1; j < length; j++){
			if(v[j] < v[min]){
				min = j;
			}
		}
		if(i != min){ // swap
			key = v[i];
			v[i] = v[min];
			v[min] = key;
		}
	}
}

/********* Start of MERGE functions *********/

void merge_sort(int v[], int start, int end){
	if(start < end){
		int middle = start + ((end-start) / 2);
		merge_sort(v, start, middle); // divide
		merge_sort(v, middle+1, end); // divide
		merge(v, start, middle, end); // conquer and combine
	}
}

void merge(int v[], int start, int middle, int end){
	int i = start, j = middle+1, k = start; 
	int helper[end]; // 

	for(int i=start; i<=end; i++){
		helper[i] = v[i];
	}

	// Copies the minor values of both partitions to the original vector
	while(i<=middle && j<=end){ 
		if(helper[i] <= helper[j]){
			v[k] = helper[i];
			i++;
		}
		else{
			v[k] = helper[j];
			j++;
		}
		k++;
	}

	// Copies the rest of the left partition
	while(i <= middle){
		v[k] = helper[i];
		i++;
		k++;
	}

	// Copies the rest of the right partition
	while(j <= end){
		v[k] = helper[j];
		j++;
		k++;
	}
}
/********* End of MERGE functions *********/


/********* Start of QUICK functions *********/

// The pivot is the last element of the vector
void quick_sort_last(int v[], int start, int end){
	if(start < end){
		int middle = partition(v, start, end);
		quick_sort_last(v, start, middle-1); // Left half
		quick_sort_last(v, middle+1, end); // Right half
	}
}

int partition(int v[], int start, int end){
	int pivot = v[end];
	int i = start - 1;
	for(int j=start; j<end; j++){ // Comparison
		if(v[j] <= pivot){
			i++;
			swap(v, i, j);
		}
	}
	swap(v, i+1, end);
	return i+1;
}

void swap(int v[], int i, int j) {
    int hold = v[i];
    v[i] = v[j];
    v[j] = hold;
}

/********* End of QUICK functions *********/


/********* Start of HEAP functions *********/

int parent(int i){
	return i/2;
}

int left(int i){
	return i*2;
}

int right(int i){
	return 2*i+1;
}

/* Calls max_heapify recursively for nodes
   that are not in max heap property.
*/
void max_heapify(int v[], int length, int i){
	int l = left(i);
	int r = right(i);
	int largest;

	if(l <= length && v[l] > v[i]){ // Checks if left node is the largest
		largest = l;
	}
	else{
		largest = i;
	}

	if(r <= length && v[r] > v[largest]){ // Checks if right node is the largest
		largest = r;
	}
	
	if(largest != i){ // Checks if there was exchange
		swap(v, i, largest);
		max_heapify(v, length, largest);
	}
}

/* Calls max_heapify for every node in a bottom-up manner */
void build_max_heap(int v[], int length){
	for(int i=length/2; i>=0; i--){
		max_heapify(v, length, i);
	}
}

/* Builds the heap, exchanges the root element with v[n] element of the heap
	and keeps the heap property */
void heapsort(int v[], int length){
	build_max_heap(v, length); 
	for(int i=length; i>=1; i--){
		swap(v, 0, i); // Exchanges the root element with v[i]
		length--; // Root nodes already exchanged stays out of the new heap range
		max_heapify(v, length, 0); // Avoids the new first element to violate the heap property
	}
}
/********* End of HEAP functions *********/