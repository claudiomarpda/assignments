#ifndef IMPORTERT_H
#define IMPORTERT_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char *COORDINATE_PATTERN = "coordIndex=\"";
const char *POINT_PATTERN = "point=\"";
#define POINTS_PER_FACE 3

typedef struct Face { // face of a model with triangle vertices
	int pointIndex[POINTS_PER_FACE];
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

FaceList *faceList;
PointList *pointList;

// function prototypes
int readFile (const char* fileName);
int readFace(FILE *inFile, char *buffer);
int readPoint(FILE *inFile, char *buffer);
void insertFace(FaceList *list, const int coordinate[]);
void insertPoint(PointList *list, const float x, const float y, const float z);
void freePoints();
void freeFaces();
void printFaceList();
void printPointList();
Point* getPointAt(const unsigned int index);

#endif // IMPORTERT_H