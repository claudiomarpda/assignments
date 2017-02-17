#include <stdio.h>
#include <GL/glut.h>

// Display the screne
void display(){
	
	//glClearColor(0.1, 0.5, 0.8, 1);	 
	glClearColor(1, 1, 1, 1);	 
	glClear(GL_COLOR_BUFFER_BIT);

	//glLoadIdentity();
	glRotatef(1, 0, 1, 0);

	// Draw triangles
	glBegin(GL_TRIANGLES);
		glColor3f(1, 0, 0);
		// set the color for all upcoming draw calls
		//glColor3f(1, 1, 1);
		// create a geometric point
		// x, y, z
		glVertex3f(-0.5, -0.5, 0.0);
		glColor3f(0, 1, 0);
		glVertex3f(0.5, -0.5, 0.0);
		glColor3f(0, 0, 1);
		glVertex3f(0.0, 0.5, 0.0);

	glEnd();

	glutSwapBuffers();
	glFlush();
}

/**
	GLUT calls this routine when the widnow is resized
*/
void reshape(int width, int height){
	glViewport(0, 0, width, height);
}

/*void initOpengl(){
	glClearColor(0, 0, 0, 1);	 

	glFlush();
}*/

int main(int argc, char **argv){
	puts("foi");

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("my opengl program");

	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();

	return 0;
}
