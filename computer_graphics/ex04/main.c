/**
	A 3d cube was exported from blender with triangle vertices.
	This program reads this file, look for cube data and store then in structures.
	The data are face and point coordinates.
	The data can be found after a pattern as described in the constant variables below.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Face { // triangle face
	int point[3];
	struct Face *next;
} Face;


typedef struct Point {
	float x;
	float y;
	float z;
	struct Point *next;
} Point;

typedef struct FaceList {
	struct Face *first;
	struct Face *last;
} FaceList;

typedef struct PointList {
	struct Point *first;
	struct Point *last;
} PointList;

const char *COORDINATE_PATTERN = "coordIndex=\"";
const char *POINT_PATTERN = "point=\"";
const int CUBE_FACES = 6;
const int CUBE_POINTS = 8;

FaceList *faceList = NULL;
PointList *pointList = NULL;

// function prototypes
void readFile (const char* fileName);
//void readPoint(int);
//void readFace();
void insertPoint(PointList *list, float x, float y, float z);
void insertFace(FaceList *list, int coordinate[]);
void freePoints();
void freeFaces();

/**
	Reads a file and looks for data defined as constant at the top of the file.
*/
void readFile (const char* fileName) {
	FILE *inFile, *outFile;
	inFile = fopen (fileName, "r");
	char *pFirstOcurrence;

	// for reading test only
	/*
	char outName[50];
	strcpy(outName, "cpy_");
	strcat(outName, fileName);
	outFile = fopen(outName, "w");
	*/

	if(inFile == NULL){
		puts("File could not be opened");
		exit(1);
	}

	char buffer[1024];
	int coordinateWasFound = 0; // flag

	do {
		fscanf(inFile, "%s", buffer); 

		// for file reading test only
		// writes a new file with the same data
		/*
		fprintf(outFile, "%s", buffer); 
		printf("%s\n", buffer);
		*/

		// look for the coordinate ocurrence
		if(!coordinateWasFound){
			pFirstOcurrence = strstr(buffer, COORDINATE_PATTERN);
			if(pFirstOcurrence != NULL){

				/* 
				 after finding the pattern, the result string should be something like
				 coordIndex="1
				 now is necessary to get this number that is sticked to the string, which is a face coordinate value
				 to do that, the string is splitted in tokens
				*/
				char *token = strtok(pFirstOcurrence, "\""); // split in quotation: "
				token = strtok(NULL, "\""); // gets the right side of the string, which is the number

				int facePoint[3], unusedPoint;
				facePoint[0] = atoi(token);				
				fscanf(inFile, "%d %d %d", &facePoint[1], &facePoint[2], &unusedPoint); // read two more face coordinates
				insertFace(faceList, facePoint);

				// gets the others coordinate values
				while(fscanf(inFile, "%d %d %d %d", &facePoint[0], &facePoint[1], &facePoint[2], &unusedPoint) > 0){
					insertFace(faceList, facePoint);
				}

				coordinateWasFound = 1; // flag
			}
		}

		// look for point pattern, and then the values
		if(coordinateWasFound){
			pFirstOcurrence = strstr(buffer, POINT_PATTERN);

			if(pFirstOcurrence != NULL){

				/* 
				 after finding the pattern, the result string should be something like
				 point="1.000000
				 now is necessary to get this number that is sticked to the string, which is a coordinate value
				 to do that, the string is splitted in tokens
				*/
				char *token = strtok(pFirstOcurrence, "\""); // split in quotation: "
				token = strtok(NULL, "\""); // gets the right side of the string, which is the number

				float x, y, z;
				x = atof(token);
				fscanf(inFile, "%f %f", &y, &z);
				insertPoint(pointList, x, y, z);

				// gets the others coordinate values
				while(fscanf(inFile, "%f %f %f", &x, &y, &z) > 0){
					insertPoint(pointList, x, y, z);
				}
			}
		}
	}
	while (!feof (inFile));
	fclose (inFile);

	// for file reading test only
	//fclose (outFile); 
}

/*
	Inserts Face elements in the end of the list.
	@param coordinate[] are the three coordinate face points.
*/
void insertFace(FaceList *list, int coordinate[]) {
	Face *newFace = (Face*) malloc(sizeof(Face));
	newFace->point[0] = coordinate[0];
	newFace->point[1] = coordinate[1];
	newFace->point[2] = coordinate[2];

	if(list->first == NULL) {
		list->first = newFace;
	}
	else{
		list->last->next = newFace; // links the last to the new one
	}
	newFace->next = NULL;
	list->last = newFace; // updates the last
}

/**
	Walks through the list and print its data.
*/
void printFaceList() {
	puts("printing faces...");
	Face *face = faceList->first;
	while(face != NULL){
		printf("%d %d %d\n", face->point[0], face->point[1], face->point[2]);
		face = face->next;
	}
}

/*
	Inserts Point elements in the end of the list.
	@param x, y, z are the three coordinate points of the cartesian plane.
*/
void insertPoint(PointList *list, float x, float y, float z) {
	Point *newPoint = (Point*) malloc(sizeof(Point));
	newPoint->x = x;
	newPoint->y = y;
	newPoint->z = z;

	if(list->first == NULL) {
		list->first = newPoint;
	}
	else{
		list->last->next = newPoint; // links the last to the new one
	}
	newPoint->next = NULL;
	list->last = newPoint; // updates the last
}

/**
	Walks through the list and print its data.
*/
void printPointList() {
	puts("printing points...");
	Point *point = pointList->first;
	while(point != NULL){
		printf("%f %f %f\n", point->x, point->y, point->z);
		point = point->next;
	}
}


int main(){

	faceList = (FaceList*) malloc(sizeof(FaceList));
	pointList = (PointList*) malloc(sizeof(PointList));

	readFile("cube.x3d");
	printFaceList();
	printPointList();
	return 0;
}