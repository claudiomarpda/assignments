/**
	Try to make 3D effect with color mask and an object imported from X3D file.
	The X3D file uses triangle faces.
	GL optimization list is used to display the model.

	Compile with:
		gcc main.c -o main -lGL -lGLU -lglut
*/

#include "GL/glut.h"
#include <stdio.h>
#include "importer/importer_t.c"

// prototypes
void keyboardInput(unsigned char key, int x, int y);
void changeScreenSize(GLsizei w, GLsizei h);
void defineVisualization();
void defineObserver();
void init();
void loadModel();
void draw();

const char* CYLINDER_FILE = "model/tcylinder.x3d";
const char* MONKEY_FILE = "model/tmonkey.x3d";

const GLfloat PI = 3.1416f;
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

    if(readFile(CYLINDER_FILE)) {
    	loadModel();
    	puts("Model loaded.");
    }
    else {
        puts("Something is wrong. Model data were not saved in list");
        exit(1);
    }
    
    freeFaces();
    freePoints();
}

/**
    Loads models in optmization lists of the opengl
*/
void loadModel() {
    int iFace = 0; // face index
    Face* face = faceList->first;
    Point* point;

    glGenLists(1); // create one display list
    glNewList(1, GL_COMPILE);       
        glBegin(GL_LINE_LOOP); // wire frame
        // glBegin(GL_TRIANGLES); // solid

            // iterates through list of faces
            while(face != NULL){

                // searches for points according to face indexes
                for(int i = 0; i < POINTS_PER_FACE; i++) {
                    point = getPointAt(face->pointIndex[i]);
                    glVertex3f(point->x, point->y, point->z);
                }
                face = face->next;
                iFace++;
            }
        glEnd();
    glEndList();
}

/**
	Callback. Draws the object stored in the list on the screen.
*/
void draw() {
	glClear(GL_COLOR_BUFFER_BIT);

	// trying to make transparent effect	
	// glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// allows writing only in blue color and alpha
	glColorMask(0, 0, 1, 1);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f); // blue
	// draws the loaded model
	glCallList(1);
	// translates a little bit to position the second model in a 3D effect
	glTranslatef(0, -0.2, 0);
	// allows writing only in red color and alpha
	glColorMask(1, 0, 0, 1); // red
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f); // red
	// draws the loaded model
	glCallList(1);

	// run the opengl commands
	glutSwapBuffers();
	// allows writing in r, g, b, a
	glColorMask(1, 1, 1, 1);
 }

/**
	Specifies the visualization volume
*/
void defineVisualization() {
	// specifies coordenate system projection
	glMatrixMode(GL_PROJECTION);
	// initializes coordenate system projection
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
	// specifies the coordenate system of the model
	glMatrixMode(GL_MODELVIEW);
	// initializes coordenate system of the model
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

	// lists of faces and points from importer_t. to read X3D model
    faceList = (FaceList*) malloc(sizeof(FaceList));
    pointList = (PointList*) malloc(sizeof(PointList));

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(800,600);
	glutCreateWindow("3D Color Mask");
	glutDisplayFunc(draw);
    glutReshapeFunc(changeScreenSize);
	glutKeyboardFunc(keyboardInput);

	// trying to make transparent effect
	// glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// glEnable(GL_DEPTH_TEST); 

	glEnable(GL_BLEND);
	init();
	glutMainLoop();
}