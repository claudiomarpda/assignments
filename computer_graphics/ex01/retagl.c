#include <GL/glut.h>
#include <stdlib.h>

// Function prototypes
void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);


int main(int argc, char** argv){
	glutInit(&argc, argv);
	// inicializa o glut
	// especifica o uso de buffer e modo de cores
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	
	// especifica as dimensoes da janela
	glutInitWindowSize (1080, 720);
	//glutInitWindowSize (540, 320);
	//glutInitWindowSize (320, 180);
	// especifica aonde a janela aparece na tela
	
	glutInitWindowPosition (100, 100);
	glutCreateWindow ("Draw a line");
	// cria a janela
	init();
	// funcao que sera redesenhada pelo GLUT
	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard); // funcoes de teclado
	glutMainLoop(); // mostra todas as janelas criadas
	return 0;
}

// definicao de cada funcao
void init(){
	glClearColor(0.0, 0.0, 0.0, 1.0);
	// cor de fundo
	// define os eixos do modo de projecao ortogonal
	glOrtho (0, 256, 0, 256, -1 ,1);
	glColor3d(1, 1, 0);
}

void display(){
	GLfloat m, x1, x2, y1, y2, y, x;
	glClear(GL_COLOR_BUFFER_BIT); // apaga tela

	// define pontos iniciais e finais para a reta no primeiro octante
	//x1=20; y1=50; x2=280; y2=100;
	x1 = 0; y1 = 0; x2 = 140; y2 = 80;
	m = (y2 - y1) / (x2 - x1);

	// calcula inclinacao
	// traça reta incrementando x de 1 em 1 e y sendo calculado
	for(x = x1; x <= x2; x += 0.5){
		y = (y1 + m * (x - x1));
		glBegin(GL_POINTS);
		glVertex2f(x,y);
		glEnd();
	}
	glFlush(); // flushes on the screen what was drawn
}

void keyboard(unsigned char key, int x, int y){
	switch (key) {
		case 27:
		// Esc key closes the program
		exit(0);
		break;
	}
}