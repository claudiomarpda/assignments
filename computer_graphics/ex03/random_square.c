/**
	fev 2017

	Basic of computer graphics.

	gcc -o run random_square.c -lglut -lGLU -lGL
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
    int white_counter = 0;
    int black_counter = 0;
    int strong_counter = 0;

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

            // forces only strong colors
            if(strong_counter++ % 2 == 0){
                if(r > g) {
                    g = 0;
                }
                else {
                    r = 0;
                }
                if(g > b) {
                    b = 0;
                }
                else {
                    g = 0;
                }
                if(b > r){
                    r = 0;
                }
            }


            if(black_counter++ % 5 == 0) {
                r = g = b = 0;
            }
            if(white_counter++ % 20 == 0) {
                r = g = b = 1;
            }
        
            // change color
            glColor3f(r, g, b); // random color
            
            // draw quads
            glBegin(GL_QUADS);
                glVertex2f(x1, y1); // top left 
                glVertex2f(x2, y2); // top right

                glVertex2f(x3, y3); // bottom right
                glVertex2f(x4, y4); // bottom left
            glEnd();

            glFlush();
        
            // new dimensions for quads
            x1 += 0.25;
            x2 -= 0.25;
            x3 -= 0.25;
            x4 += 0.25;

            y1 -= 0.25;
            y2 -= 0.25;
            y3 += 0.25;
            y4 += 0.25;

            sleep(1);

        }
    }

}

int main(int argc, char **argv){ 	
    glutInit(&argc, argv);
    glutInitWindowSize(1920, 1080);
    glutCreateWindow("opengl");
    glutInitWindowPosition(150, 50);
    glutDisplayFunc(display);

    srand(time(NULL));
    init();
    glutMainLoop();
	
    return 0;
}
