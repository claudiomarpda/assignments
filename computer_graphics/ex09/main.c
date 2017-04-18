#include <stdlib.h>
#include <GL/glut.h>

#include "importer_t.c"

int width;
int height;
int listIndex = 0;

/**
    Sets two viewports, one for each model loaded
*/
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glRotated(30, 1, 0, 0);
    glRotated(30, 0, 1, 0);

    glViewport(0, 0, width/2, height);
    glLoadIdentity();
    glColor3d(0, 1, 0);
    gluLookAt(0.0, 5.0, -3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glCallList(1);

    glViewport(width/2, 0, width/2, height);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 2.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glColor3d(0, 0, 1);
    glCallList(2);
    
    glFlush();
}

void reshape(int w, int h) {
    width = w;
    height = h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

/**
    Loads models in optmization lists of the opengl
*/
void loadModel() {
    int iFace = 0; // face index
    Face* face = faceList->first;
    Point* point;

    glGenLists(++listIndex); // create one display list
    glNewList(listIndex, GL_COMPILE);       
        glBegin(GL_LINE_LOOP); // wire frame
        // glBegin(GL_TRIANGLE); // solid

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

void init() {
    // glClearColor(0.0, 0.0, 0.0, 0.0);
    glClearColor(1.0, 1.0, 1.0, 1.0);

    if(readFile("model/tcylinder.x3d")) {
    puts("Cylinder loaded.");
    loadModel();
    }
    else {
        puts("Something is wrong. Cylinder data were not saved in list");
        exit(1);
    }

    // temporary solution
    // reset the pointers to null before storing new model
    faceList->last = NULL;
    pointList->last = NULL;
    faceList->first = NULL;
    pointList->first = NULL;

    if(readFile("model/tsphere.x3d")) {
        puts("Monkey loaded.");
        loadModel();
    }
    else {
        puts("Something is wrong. Cube data were not saved in list");
        exit(1);
    }
    
    freeFaces();
    freePoints();
}

int main(int argc, char** argv) {

    faceList = (FaceList*) malloc(sizeof(FaceList));
    pointList = (PointList*) malloc(sizeof(PointList));

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    
    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return EXIT_SUCCESS;
}