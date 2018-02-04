#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include "rngs.h"
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int main (int argc, char** argv){
    
    //define variables
    struct gameState* curState;
    
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron};
    
    int seed = 2;
    int result = 0;
    int fCount = 0;
    int befHand =0;
    int aftHand =0;
    int bonus = 0;
    
    
    printf("\n********************************************************************\n");
    printf("********************************************************************\n\n");
    printf("                            CARD TEST 1                             \n");
    printf("                        Testing Card: Smithy                        \n\n");
    printf("********************************************************************\n");
    printf("********************************************************************\n\n\n");
    
    printf("********************* TEST 1:  Gaining 3 cards *********************\n");
    
    curState = newGame();
    initializeGame(2, k, seed, curState);
    
    befHand = curState->handCount[2];
    printf("Handcount before gaining: %d\n", befHand);
    
    gainCard(smithy, curState, 2, 2);
    
    aftHand = curState->handCount[2];
    printf("Handcount after gaining: %d\n", aftHand);
    
    cardEffect(smithy, 0, 0, 0, curState, 0, &bonus);
    aftHand = curState->handCount[2];
    printf("Handcount after effect: %d\n", aftHand);
    
    printf("    Expected result: %d\n", befHand + 3);
    
    if (result == befHand + 3) {
        printf("    Actual result  : %d\n",aftHand);
        printf("    PASSED!\n");
    }
    else{
        printf("    Actual result  : %d\n",aftHand);
        printf("    FAILED\n");
        //increment fail count
        fCount++;
    }
 
    printf("\n************ TEST 2:  Verify card is used correctly  **************\n");
    
    curState = newGame();
    initializeGame(2, k, seed, curState);
    
    gainCard(smithy, curState, 2, 2);
    
    result = cardEffect(smithy, 0, 0, 0, curState, 0, &bonus);
    
    printf("    Expected result: 0\n");
    
    if (result == 0) {
        printf("    Actual result  : %d\n",result);
        printf("    PASSED!\n");
    }
    else{
        printf("    Actual result  : %d\n",result);
        printf("    FAILED\n");
        //increment fail count
        fCount++;
    }
    
    printf("\n\n************************* TESTING COMPLETE *************************\n");
    
    if (fCount > 0){
        printf("\n                      %d OF THE TESTS FAILED!\n\n", fCount);
    }
    else
        printf("\n                      ALL TESTS WERE PASSED!!\n\n");
}



