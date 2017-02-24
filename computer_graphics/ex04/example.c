typedef struct Face { // triangle face
	int pt[3];
} Face;

typedef struct Point {
	float x;
	float y;
	float z;
} Point;

/*
typedef struct List {
	Face face;
	Face* next;
}
*/

Face *f = 0;
Ponto *p = 0;

// function prototypes
void insertPoint();
void insertFace();
void readPoint(int);
void readFace();
void readFile();
void freePoints();
void freeFaces();
