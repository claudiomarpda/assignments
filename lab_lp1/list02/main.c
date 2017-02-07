#include "list02.h"
#include <stdlib.h>
#include <stdio.h>


/**
	Choose an exercise between 1 and 7
	./run 1 1
	./run 1 2
	./run 1 ...
*/
int main(int argc, char* argv[]) {

	int exercise_selection = atoi(argv[2]);	

	if(exercise_selection < 1 || exercise_selection > 7){
		printf("Argument for exercise number must be between 1 and 6.\n");
		return 0;
	}

	switch(exercise_selection){
		case 1: {
			int hour, minute;

			printf("Exercise 01\n");
			printf("Enter hour: ");
			//cin >> hour;
			scanf("%d", &hour);
			printf("Enter minute: ");
			//cin >> minute;
			scanf("%d", &minute);

			ex01(hour, minute);
			break;
		}
		case 2:
			printf("Exercise 02\n");
			int n1;
			printf("Enter an integer value (better when 1:40): ");
			scanf("%d", &n1);
			ex02(n1);
			break;

		case 3:
			printf("Exercise 03\n");
			int n2;
			printf("Enter an integer value (better when 1:40): ");
			scanf("%d", &n2);
			ex03(n2);
			break;

		case 4:
			printf("Exercise 04 (4.a)\n");
			int dividend, divisor;
			printf("Enter dividend: ");
			scanf("%d", &dividend);
			printf("Enter divisor: ");
			scanf("%d", &divisor);

			if(is_divisible(dividend, divisor)){
				printf("Is divisible\n");
			}
			else{
				printf("Not divisible\n");	
			}	
			break;

		case 5:
			printf("Exercise 05 (4.b)\n");
			int n3;
			printf("Enter number: ");
			scanf("%d", &n3);
			
			if(is_prime(n3)){
				printf("Is prime\n");
			}
			else{
				printf("Not prime\n");	
			}	
			break;

		case 6:
			printf("Exercise 06\n");
			ex05();
			break;
		case 7:
			printf("Exercise 07\n");
			ex06();
			break;
	}

    return 0;

}