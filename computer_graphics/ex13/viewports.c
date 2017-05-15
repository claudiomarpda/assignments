/**
    Two viewports with frustum and perspective projection view.

    Compile in terminal with:
        gcc viewports.c -o viewports -lGL -lGLU -lglut
*/

#include <stdlib.h>
#include <GL/glut.h>

const float width = 1000.0f;
const float height = 500.0f;
const float depth = 100.0f;

void draw() {
    glBegin(GL_TRIANGLE_STRIP);
        glVertex3d(0, 1, 0);
        glVertex3d(-1, 0, 0);
        glVertex3d(1, 0, 0);
    glEnd();
}

void orthogonalProjection() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5, 5, -5, 5, -5, 5);
    glMatrixMode(GL_MODELVIEW);
}

void frustumProjection() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1.0, 1.0, -1.0, 1.0, 0.5, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

/**
    Draws in two viewports.
*/
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    orthogonalProjection();
    glViewport(0, 0, 500, 500);
    glLoadIdentity();
    glColor3d(1, 0, 0);
    draw();

    frustumProjection();
    glViewport(500, 0, 500, 500);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 2.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glColor3d(0, 0, 1);
    draw();

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    
    init();

    glutDisplayFunc(display);
    glutMainLoop();
    return EXIT_SUCCESS;
}