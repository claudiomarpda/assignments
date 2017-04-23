/**	
	Earth and sun movement simulation.
	The idea is to find out something that shouldn't happen in reality.
	Uses sin and cosin functions from math.h to make objects go around in circle.
	The problem is that the earth(blue) never goes behind the [fixed] sun(yellow)
	You must enable and disable(comment) the rotateView to see it.

	Compile with:
	gcc solar-system.c -o solar-system -lm -lGL -lGLU -lglut
*/

#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

float position = 0;
double x;
double y;
const float RADIUS = 20.0f;
const float MOVE_SPEED = 0.1f;

int width = 1000;
int height = 500;

void reshape(int w, int h) {
    width = w;
    height = h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

void drawAxes() {
	glBegin(GL_LINES);
		// x red
		glColor3d(1, 0, 0);
		glVertex3d(0, 0, 0);
		glVertex3d(50, 0, 0);

		// y green
		glColor3d(0, 1, 0);
		glVertex3d(0, 0, 0);
		glVertex3d(0, 50, 0);

		// z blue
		glColor3d(0, 0, 1);
		glVertex3d(0, 0, 0);
		glVertex3d(0, 0, 50);
	glEnd();
}

void initView() {
	glMatrixMode(GL_PROJECTION);
    glOrtho(-30.0, 30.0, -30.0, 30.0, -30.0, 30.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboardInput(unsigned char key, int x, int y) {
	switch(key) {
		case 'q':
			exit(0);
			break;
		case 033: // esc key
			glClear(GL_COLOR_BUFFER_BIT);
			break;
		case 'a':
		case 'A':
			position -= MOVE_SPEED;
			break;
		case 'd':
		case 'D':
			position += MOVE_SPEED;
			break;
	}
	printf("key %c\n", key);
	glutPostRedisplay();
}

/**
	Rotates the view to make it easy to see the axes in 3D.
*/
void rotateView() {
 	glRotated(90, 90, 0, 0);
	// glRotated(0, 0, 1, 0);
}

void drawEarthAndSun() {
	glColor3d(1, 1, 0);
	glutWireSphere(5, 30, 30);

	x = cos(position) * RADIUS;
	y = sin(position) * RADIUS;
	glTranslated(x, 0, 0);
	glTranslated(0, y, 0);
	glColor3d(0, 0, 1);
	glutSolidSphere(5, 30, 30);
}

/**
	Shows the same drawing and movement from different perspective.
*/
void display() {
	//clear screen
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);
  	glLoadIdentity();// clear all transformations

	// see object(earth) overlappig the fixed one(sun)
	glViewport(0, 0, width/2, height);
	glLoadIdentity();
	rotateView();
	drawAxes(); // draw x,y and z
	drawEarthAndSun();

	// rotateView to show object(earth) moving in circle
	glViewport(width/2, 0, width/2, height);
	glLoadIdentity();
	drawAxes(); // draw x,y and z
	drawEarthAndSun();

	glFlush();
}

void initGlut(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // the operation mode
	glutInitWindowSize(width, height); // size in pixels
	glutCreateWindow(argv[0]); // creates the window with its title
	glutKeyboardFunc(keyboardInput);
	initView();
	glutDisplayFunc(display); // draw my art :)
	glutMainLoop(); // endless loop
}

int main(int argc, char **argv){
  	initGlut(argc, argv);
    return 0;
}
