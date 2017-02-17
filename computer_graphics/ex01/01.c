//gcc -o foo foo.c -lglut -lGLU -lGL -lm

// #include <windows.h>  // A Magia do Windows
#include <GL/glut.h>

void display() {
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(-50, 50, -50, 50);


    glColor3d(1, 0, 0);
    int i;
    double y;
    for(i=0; i<=14; i++){
        y = i*0.57;
        glBegin(GL_POINTS);
            glVertex2i(i, (int)y);
        glEnd();
    }

//    glBegin(GL_LINES);
//        glVertex2i(0, 0);
//        glVertex2i(300, 0);
//    glEnd();


//    glBegin(GL_POINTS);
//        glVertex2i(1, 0);
//    glEnd();
//
//    glBegin(GL_POINTS);
//        glVertex2i(2, 0);
//    glEnd();
//
//    glBegin(GL_POINTS);
//        glVertex2i(3, 0);
//    glEnd();


    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Casa");
    glutDisplayFunc(display);
    glutMainLoop();
return 0;
}
