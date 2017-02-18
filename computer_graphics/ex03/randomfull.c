/**
	fev 2017

	Basic of computer graphics.

	gcc -o run randomfull.c -lglut -lGLU -lGL
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
    while(1){
    glClear(GL_COLOR_BUFFER_BIT);

        float r, g, b;

        r = (float) rand() / RAND_MAX;
        g = (float) rand() / RAND_MAX;
        b = (float) rand() / RAND_MAX;
            
        glClearColor(r, g, b, 0);

        sleep(1);
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
