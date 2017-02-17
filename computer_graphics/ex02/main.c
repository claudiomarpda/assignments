/**
	@author: Claudiomar Araújo
	02/14/2017

	Basic of computer graphics: drawing lines.

	gcc -o run main.c -lglut -lGLU -lGL
*/

#include <stdio.h>
#include <GL/glut.h>
#include <time.h>	

/**
	Prints a line on the screen using Straight line equation.
*/
void draw_line(float x1, float y1, float x2, float y2){
	float m = (y2-y1) / (x2-x1);
	float x, y;

	// set the color for all upcoming draw calls
	glColor3f(1, 0, 1);

	// Draw points
	glBegin(GL_POINTS);
		// Iterates through line coordinates
		for(x = x1; x <= x2; x+=1){
			y = (y1 + m * (x - x1));
			// creates a geometric point
			glVertex2i((int)x, (int)y);
		}
	glEnd();
	glFlush();
}

/**
	Prints a line on the screen using DDA 
	(Digital Differential Analyzer) algorithm.
*/
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

    i = 1;

    // Iterates through line coordinates
    while(i <= pixel) {
    	// Draws rounded value of x and y
    	glBegin(GL_POINTS);
    		glVertex2i((int)x, (int) y);
    	glEnd();

		x = x+dx;
		y = y+dy;
		i = i+1;
    }
}

/**
	Prints a line on the screen using Bresenham algorithm.
*/
void bresenham(int x0, int y0, int x1, int y1) {
 
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
	glBegin(GL_POINTS);
		glVertex2i((int)x0, (int) y0);
	glEnd();

	if (x0==x1 && y0==y1) break;
	e2 = err;
	if (e2 > -dx) { err -= dy; x0 += sx; }
	if (e2 < dy) { err += dx; y0 += sy; }
  }
}

void display(){
	glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-300, 300, -300, 300); // the screen limits

	clock_t t;
	float seconds;

	t = clock();

	printf("Drawing with straight line equation...");
	glColor3f(0, 0, 0);
	for(int i = 0; i < 10000; i++){
		draw_line(0, 0, 280, 160); // my straight line equation
	}
	
	t = clock() - t;
	seconds = ((float) t) / CLOCKS_PER_SEC;
	printf(" %.2f seconds\n", seconds);

	t = clock();

	printf("Drawing line with DDA...");
	//glColor3f(0, 1, 1);
	for(int i = 0; i < 10000; i++){
		dda(0, 30, 280, 160);
	}

	t = clock() - t;
	seconds = ((float) t) / CLOCKS_PER_SEC;
	printf(" %.2f seconds\n", seconds);

	printf("Drawing line with Bresenham...");
	//glColor3f(1, 1, 0);
	for(int i = 0; i < 10000; i++){
		bresenham(0, 60, 280, 160);
	}
	
	t = clock() - t;
	seconds = ((float) t) / CLOCKS_PER_SEC;
	printf(" %.2f seconds\n", seconds);

	printf("Drawing line with Bresenham from opengl (GL_LINES)...");
	//glColor3f(1, 0, 0);
	for(int i = 0; i < 10000; i++){
		glBegin(GL_LINES);
			glVertex2i(0,90);
			glVertex2i(280, 160);
		glEnd();
	}
	
	t = clock() - t;
	seconds = ((float) t) / CLOCKS_PER_SEC;
	printf(" %.2f seconds\n", seconds);

	glFlush();

}

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("my opengl program");
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
