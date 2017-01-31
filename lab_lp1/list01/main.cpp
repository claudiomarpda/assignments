#include "list01.hpp"
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

	int exercise_selection = atoi(argv[2]);	

	if(exercise_selection < 1 || exercise_selection > 4){
		cout << "Invalid input." << endl;
		return 0;
	}

	switch(exercise_selection){
		case 1:
			cout << "Exercise 01" << endl;
			ex01();
			break;
		case 2:
			cout << "Exercise 02" << endl;
			ex02();
			break;
		case 3:
			cout << "Exercise 03" << endl;
			ex03();
			break;
		case 4:
			cout << "Exercise 04" << endl;
			ex04();
	}

    return 0;

}