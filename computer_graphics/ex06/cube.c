/**
	3D scene. Handling keyboard input.
	Rotation and translation functions.
	Use w, a, s or d to move the cube.

	Compile with:
		gcc cube.c -o cube -lGL -lGLU -lglut
*/

#include <GL/glut.h>	
#include <stdio.h>

float xCoord = 0;
float yCoord = 0;
float zCoord = 0;
float moveSpeed = 2.0f;

float xAngle = 0;
float yAngle = 0;
float zAngle = 0;
int rotateAngle = 5;


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

void moveRight() {
	xCoord += moveSpeed;
	glTranslatef(xCoord, yCoord, 0.0f);
	glPushMatrix();
}

void moveLeft() {
	xCoord -= moveSpeed;
	glTranslatef(xCoord, yCoord, 0.0f);
	glPushMatrix();
}

void moveUp() {
	yCoord += moveSpeed;
	glTranslatef(xCoord, yCoord, 0.0f);
	glPushMatrix();
}

void moveDown() {
	yCoord -= moveSpeed;
	glTranslatef(xCoord, yCoord, 0.0f);
	glPushMatrix();
}

void keyboardInput(unsigned char key, int x, int y) {
	int defaultCase = 0;
	switch(key) {
		case 033: // esc key
			glClear(GL_COLOR_BUFFER_BIT);
			break;
		case 'w':
			moveUp();
			break;
		case 's':
			moveDown();
			break;
		case 'a':
			moveLeft();
			break;
		case 'd':
			moveRight();
			break;
	}
	printf("key %c\n", key);
	if(!defaultCase) {
		glutPostRedisplay();
	}
}

void init() {
	glMatrixMode(GL_PROJECTION);
    glOrtho(-50.0, 50.0, -50.0, 50.0, -50.0, 50.0);
    glMatrixMode(GL_MODELVIEW);
	glTranslated(0, 0, -20);
}

/**
	Rotates the view to make it easy to see the axes in 3D.
*/
void rotateView() {
 	glRotated(45, 1, 0, 0);		
	glRotated(45, 0, 1, 0);	
}

void display() {
	//clear screen	
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);	
	glLoadIdentity();

	rotateView();
	glPopMatrix();

	glColor3d(1, 1, 1);
    glutWireCube(10);

    glLoadIdentity();
    rotateView();
	drawAxes();

	glFlush();
}

int main(int argc, char **argv){    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // the operation mode
    glutInitWindowSize(1000, 1000); // size in pixels
    glutCreateWindow(argv[0]); // creates the window with its title
	glutKeyboardFunc(keyboardInput);
	init();
    glutDisplayFunc(display); // draw my art :)
    glutMainLoop(); // endless loop
    
    return 0;
}
