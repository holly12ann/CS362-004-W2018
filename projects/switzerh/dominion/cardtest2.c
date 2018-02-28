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
    int bonus = 0;
    
    
    printf("\n********************************************************************\n");
    printf("********************************************************************\n\n");
    printf("                            CARD TEST 2                             \n");
    printf("                      Testing Card: Adventurer                      \n\n");
    printf("********************************************************************\n");
    printf("********************************************************************\n\n\n");
    
    printf("\n************ TEST 1:  Verify card is used correctly  **************\n");
    
    curState = newGame();
    initializeGame(2, k, seed, curState);
    
    gainCard(adventurer, curState, 2, 2);
    
    result = cardEffect(adventurer, 0, 0, 0, curState, 0, &bonus);
    
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




