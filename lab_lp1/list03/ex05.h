#ifndef EX05_H
#define EX05_H

typedef struct Band {
	char name[30];
	char type[15];
	int members;
	int ranking;
} Band;

void addBand(char *name, char *type, int members, int ranking);
void printBand(Band band);
void printAllBands();
void printBandByRanking(int ranking);
void printBandByType(char *type);
void isFavorite(char *name);

#endif // EX05_H