/**
    Planar Geometric Transformations.
    glLoadIdentity()
    glRotatef()

	gcc animated_pinwheel.c -o animated_pinwheel -lglut -lGLU -lGL
*/

#include <GL/glut.h>	
#include <time.h>
#include <unistd.h>

GLfloat angle = 5; // first angle
float interval = 90; // in degrees
int leaves = 4; // pinwheel leaves

void init(){
    // defines the 2D visualization window

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);

    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
}

void drawLeaves() {

    glColor3f(1, 0.5, 0); // orange leaves

    for(int i = 0, angle = 5; i < leaves; i++, angle += interval) {
        

        glRotatef(angle, 0.0f, 0.0f, 1.0f);
        glBegin(GL_TRIANGLES);
            glVertex2f(0.3f, 0.3f); // bottom left
            glVertex2f(0.3f, 0.0f); // bottom right
            glVertex2f(0.0f, 0.0f); // bottom top
        glEnd();
    }
}

void drawLeavesCenter() {
    glColor3f(0.0f, 0.5f, 1.0f); // light blue
    glBegin(GL_QUADS); // needs 4 vertices for a quad
    glVertex2f(-0.1f, 0.1f); // top left
    glVertex2f(0.1f, 0.1f); // top right

    glVertex2f(0.1f, -0.1f); // bottom right
    glVertex2f(-0.1f, -0.1f); // bottom left
    glEnd();
}

void drawCenterPoint() {
    glPointSize(8);
    glColor3f(1, 1, 0); // yellow
    // center point ta connects all leaves
    glBegin(GL_POINTS);
        glVertex2d(0, 0);
    glEnd();
}

void display(){

    while(1) {

        // clear screen
        glClearColor(0, 0, 0, 0);
        glClear(GL_COLOR_BUFFER_BIT);

        drawLeaves();
        drawLeavesCenter();
        drawCenterPoint();
        glFlush(); // runs the OpenGL commands
        usleep(100 * 1000);
    }
}

int main(int argc, char **argv){ 	
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // the operation mode
    glutInitWindowSize(500, 500); // size in pixels
    glutCreateWindow(argv[0]); // creates the window with its title
    glutInitWindowPosition(0, 0); 
    init();
    glutDisplayFunc(display); // draw my art :)
    glutMainLoop(); // endless loop
	
    return 0;
}
