#ifndef EX04_H
#define EX04_H

#define COMPUTING "Computing"
#define PHYSICS "Physics"

typedef struct Student {
	char name[30];
	char address[50];
	char id[10];
	char course[30];
} Student;

void addStudent(char *name, char *address, char *id, char *course);
unsigned int numberOfStudents(char *course);

#endif // EX04_H



