/**
	02/17/2017

	Basic of computer graphics: drawing a house.

	gcc -o run house.c -lglut -lGLU -lGL
*/

#include <GL/glut.h>	
#include <math.h>

void init(){
    glClearColor(0,0,0,0);
}

/**
	Writes string in bitmap.
*/
void renderBitmapString(float x, float y, float z, char *string) {
  void* font = GLUT_BITMAP_9_BY_15;
  char *c;
  glRasterPos3f(x, y,z);
  for (c=string; *c != '\0'; c++) {
    glutBitmapCharacter(font, *c);
  }
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);

    // background
    // 
    glBegin(GL_QUADS); // needs 4 vertices for a quad
    	glColor3f(0.529f, 0.808f, 0.980f); // blue sky
    	glVertex2f(-1.0f, 1.0f); 
    	glVertex2f(1.0f, 1.0f);

		glColor3f(1.0f, 1.0f, 1.0f); // white
    	glVertex2f(1.0f, -1.0f);
    	glVertex2f(-1.0f, -1.0f);
    glEnd();

    // house walls
	//glColor3f(0.70f, 0.70f, 0.70f); // grey
    glColor3f(0.980f, 0.941f, 0.902f); // wheat
    glBegin(GL_QUADS);
    	glVertex2f(-0.80f, -0.40f); // top left 
    	glVertex2f(-0.0f, -0.40f); // top right

    	glVertex2f(-0.0f, -0.80f); // bottom right
    	glVertex2f(-0.80f, -0.80f); // bottom left
    glEnd();

    glColor3f(0.70f, 0.70f, 0.70f); // gray
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.80f, -0.40f); // top left 
        glVertex2f(-0.0f, -0.40f); // top right

        glVertex2f(-0.0f, -0.80f); // bottom right
        glVertex2f(-0.80f, -0.80f); // bottom left
    glEnd();

    // house roof
    glColor3f(0.647f, 0.165f, 0.165f); // brown
    glBegin(GL_TRIANGLES);
    	glVertex2f(-0.95f, -0.40f); // bottom left
    	glVertex2f(0.15f, -0.40f); // bottom right
    	glVertex2f(-0.40f, -0.20f); // top center
    glEnd();

    // house door
	glColor3f(0.70f, 0.70f, 0.70f); // gray
    glBegin(GL_LINE_LOOP);
    	glVertex2f(-0.70f, -0.50f); // top left 
    	glVertex2f(-0.50f, -0.50f); // top right

    	glVertex2f(-0.50f, -0.79f); // bottom right
    	glVertex2f(-0.70f, -0.79f); // bottom left
    glEnd();

    // house window
    glColor3f(0.70f, 0.70f, 0.70f); // gray
    glBegin(GL_LINE_LOOP);
        glVertex2f(-0.40f, -0.53f); // top left 
        glVertex2f(-0.10f, -0.53f); // top right

        glVertex2f(-0.10f, -0.65f); // bottom right
        glVertex2f(-0.40f, -0.65f); // bottom left
    glEnd();

    // three trunk
    glColor3f(0.545f, 0.271f, 0.075f); // gray
    glBegin(GL_QUADS);
        glVertex2f(0.65f, -0.50f); // top left 
        glVertex2f(0.55f, -0.50f); // top right

        glVertex2f(0.55f, -0.79f); // bottom right
        glVertex2f(0.65f, -0.79f); // bottom left
    glEnd();

 	// three leaves 	  
    glColor3f(0.133f, 0.545f, 0.133f); // green forest
    glBegin(GL_POLYGON); // these vertices form a closed polygon
    glVertex2f(0.4f, -0.1f);
    glVertex2f(0.8f, -0.1f);
    glVertex2f(0.9f, -0.3f);
    glVertex2f(0.8f, -0.5f);
    glVertex2f(0.4f, -0.5f);
    glVertex2f(0.3f, -0.3f);
    glEnd();

    glColor3d(1.0f, 1.0f, 1.0f);
    renderBitmapString(0.50, -0.22f, 0,"Lar");
    renderBitmapString(0.50, -0.32f, 0,"Doce");
    renderBitmapString(0.50, -0.42f, 0,"Lar");
    glFlush();
}

int main(int argc, char **argv){ 	
    glutInit(&argc, argv);
    glutCreateWindow("opengl");
    glutInitWindowSize(320, 320);
    glutInitWindowPosition(150, 50);
    glutDisplayFunc(display);
    init();
    glutMainLoop();
	
    return 0;
}
