#include <stdio.h>

void pascal_triangle(int rows){
	int v[rows][rows];	
	int r; // row index
	int c; // column index

	for(r=0; r<rows; r++){ // row loop
		for(c=0; c<r; c++){ // column loop
			if(c == 0){
				v[r][c] = 1; // the first "1" of a row
			}
			else if(c < rows-1){ // not reached the last column

				// current column receives the value of 
				// v[row-1][column-1] + v[row-1][column]
				v[r][c] = v[r-1][c-1] + v[r-1][c];
			}
			printf("%d ", v[r][c]); // the first "1" of a row or some other value
		}
		v[r][c] = 1;
		printf("%d\n", v[r][c]); // the last "1" of a row
	}
}

int main(){
	printf("Type the number of rows: ");
	int rows;
	scanf("%d", &rows);
	pascal_triangle(rows);
	return 0;
}