/**
	Gets votes for players and computes statistical values.
*/

#include <stdio.h>
#include <iostream>

using namespace std;

const int NUMBER_OF_PLAYERS = 23;
int voting[NUMBER_OF_PLAYERS];
int numberOfVotes = 0;

/**
	Player number must be between 1 and 23.

*/
void addVote(int playerNumber){

	if(playerNumber != 0 && (playerNumber < 1 || playerNumber > 23)){
		cout << "Enter a value between 1 and 23 or 0 to exit" << endl;
		return;
	}

	if(playerNumber != 0){ // ends the input
		voting[playerNumber - 1]++; // -1 for array handling
		numberOfVotes++;
	}
}

/**
	Percentual value for the reason votes / total votes.
*/
float getVotesReason(int votes){
	return ((float)votes / numberOfVotes) * 100;
}

int getBestPlayer(){
	int higher = 0; // number of votes
	int player; // player index

	for(int i = 0; i < NUMBER_OF_PLAYERS; i++){
		if(voting[i] > higher){
			higher = voting[i];
			player = i;
		}
	}
	return player;
}

/**
	Show results of the survey.
*/
void showResults(){
	cout << "Voting result:" << endl;
	cout << "Computed votes: "<< numberOfVotes << endl;

	printf("%s | %5s | %5c\n", "Player", "Votes", '%');
	for(int i = 0; i < NUMBER_OF_PLAYERS; i++){
		if(voting[i] > 0){
			printf("%3d %10d %10.1f%c\n", i+1, voting[i], getVotesReason(voting[i]), '%');
		}
	}

	if(numberOfVotes > 0){
		int bestPlayer = getBestPlayer();

		printf("\nThe best player was number %d with %d vote(s), resulting in %.1f%c of all votes.\n\n", 
			bestPlayer + 1, 
			voting[bestPlayer],
			getVotesReason(voting[bestPlayer]),
			'%');
	}
	else{
		cout << "0 votes found" << endl;
	}
}
