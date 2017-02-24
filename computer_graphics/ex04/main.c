/**
	A 3d cube was exported from blender with triangle vertices.
	This program reads this file, look for cube data and store then in list structures.
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

// function prototypes
int readFile (const char* fileName);
int readFace(FILE *inFile, const char *buffer);
int readPoint(FILE *inFile, const char *buffer);
void insertFace(FaceList *list, const int coordinate[]);
void insertPoint(PointList *list, const float x, const float y, const float z);
void freePoints();
void freeFaces();
void printFaceList();
void printPointList();

FaceList *faceList;
PointList *pointList;

int main(){

	faceList = (FaceList*) malloc(sizeof(FaceList));
	pointList = (PointList*) malloc(sizeof(PointList));

	// cube with triangle vertices
	if(readFile("tcube.x3d")) {
		puts("Face and Point data were sucessfully saved in list.");
	}
	else {
		puts("Something is wrong. Data were not saved in list");
	}

	 // simple cube
	/*if(readFile("cube.x3d")) {
		puts("Face and Point data were sucessfully saved.");
	}
	else {
		puts("Something is wrong. Data were not saved");
	}
*/	
	printFaceList();
	printPointList();
	freeFaces();
	freePoints();
	printFaceList();
	printPointList();
	return 0;
}

/**
	Reads a file and looks for data defined as constant at the top of the file.
*/
int readFile (const char* fileName) {
	FILE *inFile;
	inFile = fopen (fileName, "r");

	if(inFile == NULL){
		puts("File could not be opened");
		exit(1);
	}

	char buffer[1024];
	int coordinateWasFound = 0; // flag

	do {
		fscanf(inFile, "%s", buffer); 

		// look for the coordinate ocurrence
		if(!coordinateWasFound){
			coordinateWasFound = readFace(inFile, buffer);
		}

		// look for point pattern only after finding face data, and then the values
		if(coordinateWasFound){
			if(readPoint(inFile, buffer)){
				return 1; // data should be sucessfully saved
			}
		}
	}
	while (!feof (inFile));
	fclose (inFile);

	return 0; // data was not saved
}

/*
	Inserts Face elements in the end of the list.
	@param coordinate[] are the three coordinate face points.
*/
void insertFace(FaceList *list, const int coordinate[]) {
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
	Walks through the Face list and print its data.
*/
void printFaceList() {
	
	if(faceList == NULL){
		return;
	}	

	puts("Points data:");
	Face *face = faceList->first;
	while(face != NULL){
		printf("%d %2d %2d\n", face->point[0], face->point[1], face->point[2]);
		face = face->next;
	}
}

/*
	Inserts Point elements in the end of the list.
	@param x, y, z are the three coordinate points of the cartesian plane.
*/
void insertPoint(PointList *list, const float x, const float y, const float z) {
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
	Walks through the Point list and print its data.
*/
void printPointList() {

	if(pointList == NULL){
		return;
	}

	puts("Faces data:");
	Point *point = pointList->first;
	while(point != NULL){
		printf("%10f %10f %10f\n", point->x, point->y, point->z);
		point = point->next;
	}
}

/**
	Reads Face data according to the file pattern.
	@return 1 if the pattern was found and data was saved.
	@return 0 otherwise
*/
int readFace(FILE *inFile, const char* buffer){
	char *pFirstOcurrence = strstr(buffer, COORDINATE_PATTERN);
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

		return 1; // the coordinate was found
	}
	return 0; // the coordinate was not found
}

/**
	Reads Point data according to the file pattern.
	@return 1 if the pattern was found and data was saved.
	@return 0 otherwise
*/
int readPoint(FILE *inFile, const char *buffer){
	char *pFirstOcurrence = strstr(buffer, POINT_PATTERN);

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

		return 1; // point data should be sucessfully saved
	}	

	return 0; // point data was not saved
}

/**
	Releases the memory allocated with malloc in the whole Face list,
	including the initial list pointer.
*/
void freeFaces() {
	Face *face = faceList->first;
	Face *toBeDeleted;
	while(face != NULL){
		toBeDeleted = face;
		face = face->next;
		free(toBeDeleted);
	}
	free(faceList);
	faceList = NULL;
	puts("Face data deleted.");
}

/**
	Releases the memory allocated with malloc in the whole Point list,
	including the initial list pointer.
*/
void freePoints() {
	Point *point = pointList->first;
	Point *toBeDeleted;
	while(point != NULL){
		toBeDeleted = point;
		point = point->next;
		free(toBeDeleted);
	}
	free(pointList);
	pointList = NULL;
	puts("Point data deleted.");
}