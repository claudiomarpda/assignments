/**
	Loads a model imported from blender.
	The model is a cube with triangle vertices.
	The file format is .x3d.
	
	@see importer.h
		importer.c
		 
	Compile with:
		gcc main.c -o main -lGL -lGLU -lglut
*/

#include <GL/glut.h>	
#include <stdio.h>
#include "importer.c"

float colors[][3] = {
	{1.0f, 0.0f, 0.0f},
	{1.0f, 1.0f, 0.0f},
	{0.0f, 1.0f, 0.0f},
	{0.0f, 1.0f, 1.0f},
	{0.0f, 0.0f, 1.0f},
	{1.0f, 0.0f, 1.0f},

	{0.7f, 0.0f, 0.0f},
	{0.7f, 0.7f, 0.0f},
	{0.0f, 0.7f, 0.0f},
	{0.0f, 0.7f, 0.7f},
	{0.0f, 0.0f, 0.7f},
	{0.7f, 0.0f, 0.7f},

	{0.3f, 0.0f, 0.0f},
	{0.3f, 0.3f, 0.0f},
	{0.0f, 0.3f, 0.0f},
	{0.0f, 0.3f, 0.3f},
	{0.0f, 0.0f, 0.3f},
	{0.3f, 0.0f, 0.3f}
};

float xCoord = 0.0f;
float yCoord = 0.0f;
float zCoord = 0.0f;
float moveSpeed = 2.0f;

float xAngle = 0.0f;
float yAngle = 0.0f;
float zAngle = 0.0f;

float zoom = 1.0f;
float zoomRate = 0.2f;

float zRotationAngle = 0.0f;
float xRotationAngle = 0.0f;
float rotationInterval = 10.0f;

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

void zoomIn() {
	zoom += zoomRate;
	glScalef(zoom, zoom, zoom);
	glPushMatrix();
}

void zoomOut() {
	zoom -= zoomRate;
	glScalef(zoom, zoom, zoom);
	glPushMatrix();
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

void rotateRight() {
	zRotationAngle += rotationInterval;
	glRotatef(zRotationAngle, 0.0f, 0.0f, 1.0f);
	glPushMatrix();
}

void rotateLeft() {
	zRotationAngle -= rotationInterval;
	glRotatef(zRotationAngle, 0.0f, 0.0f, 1.0f);
	glPushMatrix();
}

void rotateUp() {
	xRotationAngle += rotationInterval;
	glRotatef(xRotationAngle, 1.0f, 0.0f, 0.0f);
	glPushMatrix();
}

void rotateDown() {
	xRotationAngle -= rotationInterval;
	glRotatef(xRotationAngle, 1.0f, 0.0f, 0.0f);
	glPushMatrix();
}

void clearAllVariables() {
	xCoord = 0.0f;
	yCoord = 0.0f;
	zCoord = 0.0f;

	xAngle = 0.0f;
	yAngle = 0.0f;
	zAngle = 0.0f;

	zoom = 1.0f;

	zRotationAngle = 0.0f;
	xRotationAngle = 0.0f;
}

void keyboardInput(unsigned char key, int x, int y) {
	int defaultCase = 0;
	switch(key) {
		case 'q':
			freePoints();
			freeFaces();
			exit(0);
			break;
		case 033: // esc key
		    clearAllVariables();
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
		case 'i':
			zoomIn();
			break;
		case 'o':
			zoomOut();
			break;
		case 'W':
			rotateUp();
			break;
		case 'S':
			rotateDown();
			break;
		case 'A':
			rotateLeft();
			break;
		case 'D':
			rotateRight();
			break;
		default:
			defaultCase = 1;	
			break;
	}
	printf("key %c\n", key);
	if(!defaultCase) {
		glutPostRedisplay();
	}
}

void initView() {
	glMatrixMode(GL_PROJECTION);
    glOrtho(-30.0, 30.0, -30.0, 30.0, -30.0, 30.0);
    //glFrustum(-30.0f, 30.0f, -30.0f, 30.0f, 1.0f, 30.0f);
    //gluPerspective(90.0f, 1.0f, 1.0f, 400.0f);
    glFrustum(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
	//glTranslated(0, 0, -20);
}

/**
	Rotates the view to make it easy to see the axes in 3D.
*/
void rotateView() {
 	glRotated(45, 1, 0, 0);		
	glRotated(45, 0, 1, 0);	
}

void drawLoadedModel() {
	int iFace = 0; // face index
	Face* face = faceList->first;
	Point* point;

	glBegin(GL_LINE_LOOP); // wire frame
	//glBegin(GL_TRIANGLES); // solid

		// iterates through list of faces
		while(face != NULL){

			// sets a different color for each face
			glColor3f(
					colors[iFace][0],
					colors[iFace][1],
					colors[iFace][2]);

			// searches for points according to face indexes
			for(int i = 0; i < POINTS_PER_FACE; i++) {
				point = getPointAt(face->pointIndex[i]);
				glVertex3f(point->x, point->y, point->z);
			}
			face = face->next;
			iFace++;
		}
	glEnd();
}

/**
	Set the translation and scale from the last scene.
*/
void previousScene() {
	glTranslatef(xCoord, 0.0f, 0.0f);
	glTranslatef(0.0f, yCoord, 0.0f);
	glScalef(zoom, zoom, zoom);
}

void display() {
	//clear screen	
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);	
	glLoadIdentity();

	rotateView();
	glPopMatrix();

    drawLoadedModel();

    glLoadIdentity();// clear all transformations
    rotateView(); // for better 3D view
	drawAxes(); // draw x,y and z

	previousScene();
	
	glFlush();
}

void initGlut(int argc, char** argv) {
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // the operation mode
    glutInitWindowSize(500, 500); // size in pixels
    glutCreateWindow(argv[0]); // creates the window with its title
	glutKeyboardFunc(keyboardInput);
	initView();
    glutDisplayFunc(display); // draw my art :)
    glutMainLoop(); // endless loop
}

int main(int argc, char **argv){

	faceList = (FaceList*) malloc(sizeof(FaceList));
	pointList = (PointList*) malloc(sizeof(PointList));

	// cube with triangle vertices
	if(readFile("tcube.x3d")) {
		puts("Face and Point data were sucessfully saved in list.");
	}
	else {
		puts("Something is wrong. Data were not saved in list");
		exit(1);
	}
	
	printFaceList();
	printPointList();

  	initGlut(argc, argv);

  	freePoints();
  	freeFaces();

    return 0;
}