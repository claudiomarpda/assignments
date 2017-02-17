#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dda(float x1, float y1, float x2, float y2){
	float x, y, dx, dy, pixel;
	int i, gd, gm;

	// Difference between two points
    dx = abs(x2 - x1);
    dy = abs(y2 - y1);


    // Identity the number os steps to put pixel.
    if(dx >= dy)
	    pixel = dx;
    else
    	pixel = dy;

    // Calculates the increment
    dx = dx / pixel;
    dy = dy / pixel;

    x = x1;
    y = y1;

    i=1;

    // Iterates through line coordinates
    while(i <= pixel) {
    	// Displays rounded value of x and y
    	//printf("(%d %d)\n", (int)x, (int)y);
		x = x+dx;
		y = y+dy;
		i = i+1;
    }
}

int main(){	

	clock_t t;
	t = clock();
	
	puts	("Drawing lines...");
	for(int i = 0; i < 100000000; i++){
		dda(0, 0, 14, 8);
		//puts("--------------");
	}

	t = clock() - t;
	float seconds = ((float) t) / CLOCKS_PER_SEC;
	printf("Elapsed time: %.2f\n", seconds);

	return 0;
}