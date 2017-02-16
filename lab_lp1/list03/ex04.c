#include "ex04.h"
#include <string.h>
#include <stdio.h>

Student students[100];
int size;

void addStudent(char *name, char *address, char *id, char *course){
	strcpy(students[size].name, name);
	strcpy(students[size].address, address);
	strcpy(students[size].id, id);
	strcpy(students[size].course, course);
	size++;
}


unsigned int numberOfStudents(char *course) {
	int number_of_students = 0;
	for(int i = 0; i < size; i++){
		// same course
		if(strcmp(students[i].course, course) == 0) {
			number_of_students++;
		}
	}
	return number_of_students;
}