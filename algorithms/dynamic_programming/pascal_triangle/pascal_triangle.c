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
	//printf("Type the number of rows: ");
	//int rows;
	//scanf("%d", &rows);
	printf("Pascal Triangle for 1 row\n");
	pascal_triangle(1);
	printf("\n");
	printf("Pascal Triangle for 2 rows\n");
	pascal_triangle(2);
	printf("\n");
	printf("Pascal Triangle for 3 rows\n");
	pascal_triangle(3);
	printf("\n");
	printf("Pascal Triangle for 5 rows\n");
	pascal_triangle(5);
	printf("\n");
	printf("Pascal Triangle for 10 rows\n");
	pascal_triangle(10);
	printf("\n");
	printf("Pascal Triangle for 15 rows\n");
	pascal_triangle(15);
	printf("\n");
	printf("Pascal Triangle for 20 rows\n");
	pascal_triangle(20);
	return 0;
}