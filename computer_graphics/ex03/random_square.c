/**
	@author: Claudiomar Araújo
	02/xx/2017

	Basic of computer graphics.

	gcc -o run main.c -lglut -lGLU -lGL
*/

#include <GL/glut.h>	
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

void init(){
    glClearColor(0,0,0,0);
}


void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    float r, g, b;

    while(1){
        float x1 = -1;
        float y1 = 1;

        float x2 = 1;
        float y2 = 1;

        float x3 = 1;
        float y3 = -1;

        float x4 = -1;
        float y4 = -1;

        while( x1 <= 1 ) {

            r = (float) rand() / RAND_MAX;
            g = (float) rand() / RAND_MAX;
            b = (float) rand() / RAND_MAX;

            glColor3f(r, g, b); // random color
            glBegin(GL_QUADS);
                glVertex2f(x1, y1); // top left 
                glVertex2f(x2, y2); // top right

                glVertex2f(x3, y3); // bottom right
                glVertex2f(x4, y4); // bottom left
            glEnd();

            glFlush();


            x1 += 0.25;
            x2 -= 0.25;
            x3 -= 0.25;
            x4 += 0.25;

            y1 -= 0.25;
            y2 -= 0.25;
            y3 += 0.25;
            y4 += 0.25;

            sleep(1.0);

        }
    }

}

int main(int argc, char **argv){ 	
    glutInit(&argc, argv);
    glutCreateWindow("opengl");
    //glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(320, 320);
    glutInitWindowPosition(150, 50);
    glutDisplayFunc(display);

    srand(time(NULL));
    init();
    glutMainLoop();
	
    return 0;
}
