#include <stdio.h>
#include <time.h>

void draw_line(float x1, float y1, float x2, float y2){
	float m = (y2-y1) / (x2-x1);
	//printf("m = %f\n", m);
	float x, y;
	for(x = x1; x <= x2; x++){
		y = (y1 + m * (x - x1));
		printf("(%d, %d)\n", (int)x, (int)y);
	}
}

int main(){
	clock_t t;
	t = clock();

	puts	("Drawing lines...");
	//for(int i = 0; i < 1000000000; i++){
		draw_line(0, 0, 14, 8);
		//puts("--------------");
	//}

	t = clock() - t;
	float seconds = ((float) t) / CLOCKS_PER_SEC;
	printf("Elapsed time: %.2f\n", seconds);

	return 0;
}