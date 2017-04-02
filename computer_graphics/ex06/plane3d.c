#include <GL/glut.h>	
#include <stdio.h>

/**
	3D axes for didactic view.
*/
void drawAxes() {
	glBegin(GL_LINES);
		// x red
		glColor3d(1, 0, 0);		
		glVertex3d(0, 0, 0);	
		glVertex3d(100, 0, 0);
		
		// y green
		glColor3d(0, 1, 0);
		glVertex3d(0, 0, 0);	
		glVertex3d(0, 100, 0);
		
		// z blue
		glColor3d(0, 0, 1);
		glVertex3d(0, 0, 0);	
		glVertex3d(0, 0, 100);
	glEnd();
}


/**
	Gets special input from keyboard.
*/
void specialInput(int key, int x, int y) {
	int defaultCase = 0;
	switch(key){
		case GLUT_KEY_UP:
			puts("KEY UP");
			break;
		case GLUT_KEY_DOWN:
			puts("KEY DOWN");
			break;
		case GLUT_KEY_LEFT:
			puts("KEY LEFT");
			break;
		case GLUT_KEY_RIGHT:
			puts("KEY RIGHT");
			break;
		default:
			defaultCase = 1;
	}
	if(!defaultCase) {
		glutPostRedisplay();
	}
}

void init() {
	glMatrixMode(GL_PROJECTION);
    glOrtho(-100.0, 100.0, -100.0, 100.0, -100.0, 100.0);
    //glOrtho(-50.0, 50.0, -50.0, 50.0, -50.0, 50.0);
    //glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);
    //glOrtho(-15.0, 15.0, -15.0, 15.0, -15.0, 15.0);
    glMatrixMode(GL_MODELVIEW);
	glTranslated(0, 0, -20);
}

/**
	Rotates the view to make it easy to see the axes in 3D.
*/
void rotateView() {
 	glRotated(40, 1, 0, 0);		
	glRotated(45, 0, 1, 0);	
	//glTranslated(-50, 0, 0);
}

void drawFigures() {
	glColor3d(0, 0, 1);

	// draw plane
	glColor3f(0.6f, 0.6f, 0.6f);	
	glBegin(GL_QUADS);
		glVertex3f(-99.0f, 0.0f, 99.f);
		glVertex3f(99.0f, 0.0f, 99.f);
		glVertex3f(99.0f, 0.0f, -99.f);
		glVertex3f(-99.0f, 0.0f, -99.f);
	glEnd();

	glColor3d(1, 1, 1);	// white
	glutWireCube(21);

	int posRight = 25;
	int posLeft = -25;
	int posUp = 25;
	int posDown = -25;
	int size = 10; // cube size

	glPushMatrix();

	// draw in positive x axis
	glColor3d(1, 0, 0);		
	for(int i = 0; i < 3; posRight += 2, i++) {
		glTranslated(posRight, 0, 0);
		glutWireCube(size);
	}

	glPopMatrix();
	glPushMatrix();

	// draw in negative x axis
	glRotated(45, 1, 0, 0);
	glColor3f(0.7f, 0.0f, 1.0f);
	for(int i = 0; i < 3; posLeft -= 2, i++) {
		glTranslated(posLeft, 0, 0);
		glutWireCube(size);
	}

	glPopMatrix();
	glPushMatrix();

	// draw in positive z axis
	glColor3f(0.0f, 0.0f, 1.0f);
	for(int i = 0; i < 3; posUp += 2, i++) {
		glTranslated(0, 0, posUp);
		glutWireCube(size);
	}

	glPopMatrix();
	glPushMatrix();

	// draw in negative z axis
	glRotated(45, 0, 0, 1);
	glColor3f(0.0f, 0.8f, 0.8f); // light blue
	for(int i = 0; i < 3; posDown -= 2, i++) {
		glTranslated(0, 0, posDown);
		glutWireCube(size);
	}	

	glPopMatrix();
	glTranslated(0, 70, 0);

	glColor3d(1, 1, 0); // yellow
	glutWireSphere(10, 10, 10);
}

void drawGroundPlane() {
	glColor3f(0.6f, 0.6f, 0.6f);	
	glBegin(GL_QUADS);
		glVertex3f(-80.0f, 0.0f, 80.f);
		glVertex3f(80.0f, 0.0f, 80.f);
		glVertex3f(80.0f, 0.0f, -80.f);
		glVertex3f(-80.0f, 0.0f, -80.f);
	glEnd();
}

void display() {
	//clear screen	
	glClearColor(0, 0, 0, 0);
	//glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);	
	glLoadIdentity();

	rotateView();
	drawFigures();
	
	glLoadIdentity();	
	glPopMatrix();

	glColor3d(1, 1, 1);

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
	glutSpecialFunc(specialInput);
	init();
    glutDisplayFunc(display); // draw my art :)
    glutMainLoop(); // endless loop
    
    return 0;
}
