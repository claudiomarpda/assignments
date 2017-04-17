/**
	Reads objects with triangle vertices from a X3D file, looks its data and store then in list structures.
	The data are face and point coordinates.
	The data can be found after a pattern as described in the constant variables in header file.
*/

#include "importer_t.h"

/**
	Reads a file and looks for data defined in header file.
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
		else {
			if(readPoint(inFile, buffer)){
				fclose (inFile);
				return 1; // all data should be sucessfully saved.
			}
		}
	}
	while (!feof (inFile));
	fclose (inFile);

	return 0; // data were not saved
}

/*
	Inserts Face elements in the end of the list.
	@param coordinate[] are the three coordinate face points.
*/
void insertFace(FaceList *list, const int coordinate[]) {
	Face *newFace = (Face*) malloc(sizeof(Face));
	newFace->pointIndex[0] = coordinate[0];
	newFace->pointIndex[1] = coordinate[1];
	newFace->pointIndex[2] = coordinate[2];

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
		puts("List is null. There is nothing to show");
		return;
	}	

	puts("Face data:");
	Face *face = faceList->first;
	while(face != NULL){
		printf("%d %2d %2d\n", face->pointIndex[0], face->pointIndex[1], face->pointIndex[2]);
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
		puts("List is null. There is nothing to show");
		return;
	}

	puts("Point data:");
	Point *point = pointList->first;
	while(point != NULL){
		printf("%10f %10f %10f\n", point->x, point->y, point->z);
		point = point->next;
	}
}

/**
	Reads Face data according to the file pattern.
	@return 1 if the pattern was found and data were saved.
	@return 0 otherwise
*/
int readFace(FILE *inFile, char* buffer){
	char *pFirstOcurrence = strstr(buffer, COORDINATE_PATTERN);
	if(pFirstOcurrence != NULL){ // Pattern was found

		/* 
		 After finding the pattern, the result string should be something like
		 coordIndex="1
		 Now is necessary to get this number that is sticked to the string, which is a face coordinate value.
		 To do that, the string is splitted in tokens.
		*/
		char *token = strtok(pFirstOcurrence, "\""); // split in quotation: "
		token = strtok(NULL, "\""); // gets the right side of the string, which is the number

		int facePoint[POINTS_PER_FACE];
		int unusedPoint;
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
	@return 1 if the pattern was found and data were saved.
	@return 0 otherwise
*/
int readPoint(FILE *inFile, char *buffer){
	char *pFirstOcurrence = strstr(buffer, POINT_PATTERN);

	if(pFirstOcurrence != NULL){ // Pattern was found

		/* 
		 After finding the pattern, the result string should be something like
		 point="1.000000
		 Now is necessary to get this number that is sticked to the string, which is a coordinate value.
		 To do that, the string is splitted in tokens.
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

	return 0; // point data were not saved
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
	puts("Face data released.");
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
	puts("Point data released.");
}

/**
	Looks for a point in PointList.

	@param index is the location.
	@return the point or NULL, if not found.
*/
Point* getPointAt(const unsigned int index) {
	Point* point = pointList->first;
	int counter = 0;

	while(point != NULL) {	
		if(counter == index) { // point found
			return point;
		}
		counter++;
		point = point->next;
	}
	return NULL; // point not found
}