#include <stdio.h>


/**
	Reads a name and prints it vertically
	Output example:
	F
	U
	L
	A
	N
	O
*/
void ex01(){
	char name[50];

	puts("Enter a name to be printed vertically: ");
	//fgets(name, sizeof(name), stdin);
	scanf("%s", &name[0]);

	for(int i = 0; i < (int)sizeof(name); i++){
		if(name[i] == '\0'){
			break;
		}
		printf("%c\n", name[i]);
	}
}

/**
	Prints a name vertically like stairs.
	Output example:
	F
	FU
	FUL
	FULA
	FULAN
	FULANO
*/
void ex02(){
	char name[50];

	puts("Enter a name to be printed vertically like stairs: ");
	//fgets(name, sizeof(name), stdin);
	scanf("%s", &name[0]);

	for(int i = 0; i < (int)sizeof(name); i++){
		int j;
		for(j = 0; j < i; j++){
			if(name[j] == '\0'){
				break;
			}
			printf("%c", name[j]);
		}
		putchar('\n');
		if(name[j] == '\0'){
			break;
		}
	}
}

/**
	Checks if a word is a palindrome.
	Ex.: ASA, ARARA
*/
int palindrome(){
	char word[50];
	puts("Enter a word for palindrome test:");
	scanf("%s", &word[0]);

	int size = 0;
	while(word[size] != '\0'){
		size++;
	}
	
	// Compares the first character with the last one
	// the second with the penultimate, and so on
	for(int i = 0, j = size - 1; i < size; i++, j--){
		if(word[i] != word[j]){
			//printf("fail %c %c", word[i], word[j]);
			return 0; // is not a palindrome
		}
	}
	return 1; // is a palindrome
}