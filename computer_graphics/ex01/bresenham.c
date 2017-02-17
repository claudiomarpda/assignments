#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void draw_line(int x0, int y0, int x1, int y1) {
 
  // Difference between two points
  int dx = abs(x1-x0);
  int dy = abs(y1-y0);

  int sx = x0<x1 ? 1 : -1;
  int sy = y0<y1 ? 1 : -1; 
  int err = (dx>dy ? dx : -dy)/2;
  int e2;
 
  while(1){
    //setPixel(x0,y0);
    //printf("(%d %d)\n", x0, y0);
    if (x0==x1 && y0==y1) break;
    e2 = err;
    if (e2 > -dx) { err -= dy; x0 += sx; }
    if (e2 < dy) { err += dx; y0 += sy; }
  }
}

int main(){
	clock_t t;
  t = clock();
  
  puts  ("Drawing lines...");
  for(int i = 0; i < 100000000; i++){
    draw_line(0, 0, 14, 8);
    //puts("--------------");
  }
  
  t = clock() - t;
  float seconds = ((float) t) / CLOCKS_PER_SEC;
  printf("Elapsed time: %.2f\n", seconds);
}