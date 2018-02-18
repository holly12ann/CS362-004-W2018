#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>


int main() {
	srand(time(NULL));
	int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron};
		
	int i, players, seed;
	int bonus=0;
	int player=0;
	//struct gameState state;
	struct gameState* curState = malloc(sizeof(struct gameState));

	printf("********************************************************************\n");
	printf("                    Running Random Smithy Tests					\n");
	printf("********************************************************************\n\n");

	for (i = 0; i < 10000; i++) {

		//generate usable random amount of players
		players = rand() % 3 + 2;

		//generate random seed
		seed = rand();		

		//initialize game
		initializeGame(players, k, seed, curState);

		//find current player
		player = whoseTurn(curState);

		//add card to hand
		gainCard(smithy, curState, 2, player);

		//test card
		cardEffect(smithy, 0, 0, 0, curState, 0, &bonus);

	}

	printf("********************************************************************\n");
	printf("                        Testing Complete					 		\n");
	printf("********************************************************************\n\n");

}



			