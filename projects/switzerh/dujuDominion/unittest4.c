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
    int fCount = 0;
    
    curState = newGame();
    initializeGame(2, k, seed, curState);
    
    printf("\n********************************************************************\n");
    printf("********************************************************************\n\n");
    printf("                            UNIT TEST 4                             \n");
    printf("                 Testing Function: updateCoins()                 \n\n");
    printf("********************************************************************\n");
    printf("********************************************************************\n\n\n");
    
    printf("*************** TEST 1: No cards in hand and 0 bonus ***************\n");
    
    updateCoins(1, curState, 0);
    
    printf("    Expected result: 0\n");
    
    if (curState->coins == 0) {
        printf("    Actual result  : %d\n",curState->coins);
        printf("    PASSED!\n");
    }
    else{
        printf("    Actual result  : %d\n",curState->coins);
        printf("    FAILED\n");
        //increment fail count
        fCount++;
    }
    
    printf("\n****************** TEST 2:  Non existant player ********************\n");
    
    updateCoins(6, curState, 8);
    
    printf("    Expected result: 0\n");
    
    if (curState->coins == 0) {
        printf("    Actual result  : %d\n",curState->coins);
        printf("    PASSED!\n");
    }
    else{
        printf("    Actual result  : %d\n",curState->coins);
        printf("    FAILED\n");
        //increment fail count
        fCount++;
    }
    
    printf("\n****** TEST 3:  3 coppers, 1 silver, 1 gold and 8 bonus coins ******\n");
    
    curState->handCount[2]=5;
    
    for (int i=0; i<5; i++){
        if (i<3){
            curState->hand[2][i]=copper;
        }
        else if (i<4){
            curState->hand[2][i]=silver;
        }
        else if (i<5){
            curState->hand[2][i]=gold;
        }
    }
    
    updateCoins(2, curState, 8);
    
    printf("    Expected result: 16\n");
    
    if (curState->coins == 16) {
        printf("    Actual result  : %d\n",curState->coins);
        printf("    PASSED!\n");
    }
    else{
        printf("    Actual result  : %d\n",curState->coins);
        printf("    FAILED\n");
        //increment fail count
        fCount++;
    }
    
    printf("\n******************* TEST 4: Incorrect card count *******************\n");
    
    curState->handCount[2]=4;
    
    updateCoins(2, curState, 8);
    
    printf("    Expected result: 16\n");
    
    if (curState->coins == 16) {
        printf("    Actual result  : %d\n",curState->coins);
        printf("    PASSED!\n");
    }
    else{
        printf("    Actual result  : %d\n",curState->coins);
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


