#include "list03.h"
#include "ex04.h"
#include "ex05.h"
#include "ex06.h"
#include <stdlib.h>
#include <stdio.h>
/**
	Choose an exercise between 1 and 6
	./run 1 1
	./run 1 2
	./run 1 ...
*/
int main(int argc, char* argv[]) {

	int exercise_selection = atoi(argv[2]);	

	if(exercise_selection < 1 || exercise_selection > 6){
		printf("Argument for exercise number must be between 1 and 6.\n");
		return 0;
	}

	switch(exercise_selection){
		case 1: {
			ex01();
			break;
		}
		case 2:
			ex02();
			break;

		case 3:
			if(palindrome()){
				puts("Is a palindrome");
			}
			else{
				puts("Not a palindrome");	
			}
			break;

		case 4:
			addStudent("Student A", "Street A", "11610001", COMPUTING);
			addStudent("Student B", "Street B", "11610002", COMPUTING);
			addStudent("Student C", "Street C", "11610003", PHYSICS);
			printf("Students of %s: %u\n", COMPUTING, numberOfStudents(COMPUTING));
			printf("Students of %s: %u\n", PHYSICS, numberOfStudents(PHYSICS));
			break;

		case 5:
			addBand("Band A", "Heavy Metal", 4, 1);
			addBand("Band B", "Rock", 3, 2);
			addBand("Band C", "Pop", 4, 3);
			addBand("Band D", "Blue", 1, 4);
			addBand("Band E", "Electronic", 1, 5);

			printAllBands();
			printBandByRanking(1);
			printBandByType("Blue");
			isFavorite("Band A");
			isFavorite("Band F");
			break;

		case 6:{
			int vote;
			puts("Survey: Who was the best player?");
			do {
				printf("Player number (0 = end):");
				scanf("%d", &vote);
				addVote(vote);
			} while(vote != 0);	

			showResults();
			break;
		}
		case 7:
			
			break;
	}

    return 0;

}