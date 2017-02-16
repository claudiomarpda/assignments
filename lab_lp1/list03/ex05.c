#include "ex05.h"
#include <string.h>
#include <stdio.h>

Band bands[5];
int size = 0;

void addBand(char *name, char *type, int members, int ranking){
	strcpy(bands[size].name, name);
	strcpy(bands[size].type, type);
	bands[size].members = members;
	bands[size].ranking = ranking;
	size++;
}

void printBand(Band band){
	printf("%s; %12s; %8d; %8d\n", 
			band.name, 
			band.type,
			band.members,
			band.ranking);
}

void printAllBands(){
	printf("%s |	 %12s | %5s | %5s\n", "Bands", "Style", "Members", "Ranking");
	puts("--------------------------------------------");
	for(int i = 0; i < size; i++){
		printBand(bands[i]);
	}
	putchar('\n');
}

void printBandByRanking(int ranking){
	for(int i = 0; i < size; i++){
		if(bands[i].ranking == ranking){
			printf("Band of ranking %d\n", ranking);
			printBand(bands[i]);
			return;
		}
	}
	puts("No band available for this ranking value");
}

void printBandByType(char *type){
	printf("Band of type %s:\n", type);
	for(int i = 0; i < size; i++){
		if(strcmp(bands[i].type, type) == 0){
			printBand(bands[i]);
		}
	}
}

void isFavorite(char *name){
	for(int i = 0; i < size; i++){
		if(strcmp(bands[i].name, name) == 0){
			printf("Band %s is a favorite\n", name);
			return;
		}
	}
	printf("Band %s is not a favorite\n", name);
}