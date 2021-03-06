#include <GL/glut.h>

int width;
int height;

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3d(1, 1, 0);
    glViewport(0, 0, width/2, height/2);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, -3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glutWireTeapot(1);

    glColor3d(1, 0, 0);
    glViewport(width/2, 0, width/2, height/2);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glutWireTeapot(1);

    glColor3d(0, 1, 0);
    glViewport(0, height/2, width/2, height/2);
    glLoadIdentity();
    gluLookAt(0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0);
    glutWireTeapot(1);

    glColor3d(0, 0, 1);
    glViewport(width/2, height/2, width/2, height/2);
    glLoadIdentity();
    gluLookAt(0.0, -3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0);
    glutWireTeapot(1);

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

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return EXIT_SUCCESS;
}