/**
	OpenGL simple lighting in 3D with perspective projection.

	Compile with:
		gcc light.c -o light -lGL -lGLU -lglut
*/

#include "GL/glut.h"
#include <stdio.h>

// prototypes
void keyboardInput(unsigned char key, int x, int y);
void changeScreenSize(GLsizei w, GLsizei h);
void defineVisualization();
void defineObserver();
void init();
void createLight();

const GLfloat OBSERVER_INTERVAL = 10.0f;
const GLfloat ANGLE_INTERVAL = 0.5f;

GLfloat angle = 15.0f;
GLfloat fAspect;
GLfloat obsX = 20, obsY = 0, obsZ = 20;

/**
	Initialize rendering parameters and model.
 */
void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glEnable(GL_LIGHTING);
  	glEnable(GL_LIGHT0);
  	glEnable(GL_COLOR_MATERIAL);
}

 /**
   Creates and configurates light for the ambient.
 */
void createLight() {
    const float ambient[] = {0.2, 0.2, 0.2, 1};
    const float difuse[] = {0.7, 0.7, 0.7, 1};
    const float position[] = {1, 3, 2, 1};
    const float specular[] = {1, 1, 1, 1};
    // const float lightAmbientModel[] = {0.2f, 0.2f, 0.2f, 1.0f};
    const float lightAmbientModel[] = {0.6f, 0.6f, 0.6f, 1.0f};

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, difuse);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lightAmbientModel);
}

void drawTeaPot() {
    glClear(GL_COLOR_BUFFER_BIT);
    createLight();
    glColor4f(0.0f, 0.8f, 0.8f, 1.0f);
    glutSolidTeapot(2);
    // glutWireTeapot(2);
    glutSwapBuffers();
 }


/**
	Specifies the visualization volume
*/
void defineVisualization() {
	// specifies coordinate system projection
	glMatrixMode(GL_PROJECTION);
	// initializes coordinate system projection
	glLoadIdentity();
	// perspective projection
	// void gluPerspective(fovy, aspect, zNear, zFar);
	gluPerspective(angle, fAspect, 0.5, 500);
	defineObserver();
}

/**
	Specifies the virtual observer position
*/
void defineObserver() {
	// specifies the coordinate system of the model
	glMatrixMode(GL_MODELVIEW);
	// initializes coordinate system of the model
	glLoadIdentity();
	// specifies the psition of the observer and target
	// void gluLookAt(eyex, eyey, eyez, centerx, centery, centerz, upx, upy, upz );
    gluLookAt(obsX, obsY, obsZ, 0, 0, 0, 1, 0, 0);
}

/**
	Callback function used when screen size is changed.
*/
void changeScreenSize(GLsizei w, GLsizei h) {
	// avoids division by 0
	if ( h == 0 ) h = 1;
	// specifies viewport size
    glViewport(0, 0, w, h);
	// calculates the aspect correction
	fAspect = (GLfloat)w/(GLfloat)h;
	defineVisualization();
}

/**
	Callback function that handles keyboard input.
*/
void keyboardInput(unsigned char key, int x, int y) {
	switch(key) {
		case 'q':
		case 'Q':
			exit(0);
			break;
		case 033: // esc key
			break;
		case 'a':
		case 'A':
			obsX -= OBSERVER_INTERVAL;
			break;
		case 'd':
		case 'D':
			obsX += OBSERVER_INTERVAL;
			break;
		case 'w':
		case 'W':
			obsY += OBSERVER_INTERVAL;
			break;
		case 's':
		case 'S':
			obsY -= OBSERVER_INTERVAL;
			break;
		case 'z':
		case 'Z':
			obsZ -= OBSERVER_INTERVAL;
			break;
		case 'x':
		case 'X':
			obsZ += OBSERVER_INTERVAL;
			break;
		case 'i':
		case 'I':
			// zoom in
			// if (angle >= 10)
			angle -= ANGLE_INTERVAL;
			break;
		case 'o':
		case 'O':
			//zoom out
			// if (angle <= 130)
			angle += ANGLE_INTERVAL;
			break;
	}
	printf("key %c\n", key);
	gluLookAt(obsX, obsY, obsZ, 0, 0, 0, 0, 1, 0);
	defineVisualization();
	glutPostRedisplay();
}

int main(int argc, char* argv[]) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800,600);
	glutCreateWindow("3D lighting");
    glutDisplayFunc(drawTeaPot);
    glutReshapeFunc(changeScreenSize);
	glutKeyboardFunc(keyboardInput);
	init();
	glutMainLoop();
}