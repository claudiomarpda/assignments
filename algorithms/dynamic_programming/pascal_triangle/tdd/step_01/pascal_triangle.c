#include <stdio.h>

void pascal_triangle(int rows){
	int r; // row index
	int c; // column index

	for(r=0; r<rows; r++){ // row loop
		for(c=0; c<r; c++){ // column loop
			if(c == 0){
				printf("1 ");
			}
			else{
				printf("* ");
			}
		}
		printf("1\n");
	}
}

int main(){
	printf("Type the number of rows: ");
	int rows;
	scanf("%d", &rows);
	pascal_triangle(rows);
	return 0;
}