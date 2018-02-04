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
    
    
    printf("\n********************************************************************\n");
    printf("********************************************************************\n\n");
    printf("                            UNIT TEST 2                             \n");
    printf("                    Testing Function:  shuffle()                    \n\n");
    printf("********************************************************************\n");
    printf("********************************************************************\n\n\n");
    
    printf("***************** TEST 1: Passing valid parameters *****************\n");
    
    curState = newGame();
    initializeGame(2, k, seed, curState);
    result = shuffle(1, curState);
    
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
    
    printf("\n**************** TEST 2:  Non existant player  ******************\n");
    
    printf("    Expected result: -1\n");
    
    //reset variables
    curState = newGame();
    result = shuffle(3, curState);
    
    if (result == -1) {
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


