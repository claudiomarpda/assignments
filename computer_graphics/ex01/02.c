//#include <windows.h>  // A Magia do Windows
#include <stdio.h>
#include <GL/glut.h>
#include <time.h>

void display() {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-50, 50, -50, 50);//limita o tamanho da tela


    glColor3d(1, 0, 0);
    int i;

    glBegin(GL_LINES);
        for(i=0; i<=1000; i++){
            glVertex2i(0, 0);
            glVertex2i(14, 8);
        }
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Casa");
    glutDisplayFunc(display);
    printf("%f", (double)clock());
    glutMainLoop();
    return 0;
}
