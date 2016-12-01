/* 	
05/08/2016

insertion
selection
merge
quick
heapsort
*/

#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H_INCLUDED

void insertion_sort(int v[], int length);

void selection_sort(int v[], int length);

void merge_sort(int v[], int start, int end);
void merge(int v[], int start, int middle, int end);

void quick_sort_last(int v[], int start, int end);
int partition(int v[], int start, int end);

void swap(int v[], int i, int j);

int parent(int i);
int left(int i);
int right(int i);
void heapsort(int v[], int length);
void build_max_heap(int v[], int length);
void max_heapify(int v[], int length, int i);

#endif
// SORTING_ALGORITHMS_H