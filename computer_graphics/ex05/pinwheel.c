/**
    Planar Geometric Transformations.
    glLoadIdentity()
    glRotatef()

	gcc pinwheel.c -o pinwheel -lglut -lGLU -lGL
*/

#include <GL/glut.h>	

void init(){
    // defines the 2D visualization window

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}


void display(){
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // stick
    glColor3d(0.2,0.2,0.2); // dark gray
    glLineWidth(5);
    glBegin(GL_LINES);
        glVertex2f(0.0f, 0.0f); // center horizontal
        glVertex2f(0.0f, -1.0f); // bottom
    glEnd();

    glColor3f(0.0f, 0.5f, 1.0f); // light blue
    glBegin(GL_QUADS); // needs 4 vertices for a quad
        glVertex2f(-0.1f, 0.1f); // top left
        glVertex2f(0.1f, 0.1f); // top right

        glVertex2f(0.1f, -0.1f); // bottom right
        glVertex2f(-0.1f, -0.1f); // bottom left
    glEnd();

    GLfloat angle = 5; // first angle
    float interval = 90; // in degrees
    int leaves = 4; // pinwheel leaves

    glColor3f(1, 0.5, 0); // orange leaves
    for(int i = 0; i < leaves; i++, angle += interval) {
        
        glRotatef(angle, 0.0f, 0.0f, 1.0f);

        // leaves
        glBegin(GL_TRIANGLES);
            glVertex2f(0.3f, 0.3f); // bottom left
            glVertex2f(0.3f, 0.0f); // bottom right
            glVertex2f(0.0f, 0.0f); // bottom top
        glEnd();
        glFlush();
    } 

    glPointSize(8);
    glColor3f(1, 1, 0); // yellow
    // center point ta connects all leaves
    glBegin(GL_POINTS);
        glVertex2d(0, 0);
    glEnd();

    glFlush(); // runs the OpenGL commands
}

int main(int argc, char **argv){ 	
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // the operation mode
    glutInitWindowSize(500, 500); // size in pixels
    glutCreateWindow(argv[0]    ); // creates the window with its title
    glutInitWindowPosition(0, 0); 
    init();
    glutDisplayFunc(display); // draw my art :)
    glutMainLoop(); // endless loop
	
    return 0;
}
