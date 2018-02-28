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
    int testK[10] = {adventurer, adventurer, feast, feast, mine, remodel, smithy, village, baron};
    
    int seed = 2;
    int curseCount = 0;
    int playerCount = 0;
    int result = 0;
    int fCount = 0;
    
    curState = newGame();
    printf("\n********************************************************************\n");
    printf("********************************************************************\n\n");
    printf("                            UNIT TEST 1                             \n");
    printf("                 Testing Function: initializeGame()                 \n\n");
    printf("********************************************************************\n");
    printf("********************************************************************\n\n\n");
    
    printf("*********************** TEST 1: Zero Players ***********************\n");
    
    result = initializeGame(0, k, seed, curState);
    
    printf("    Expected result: -1\n");

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
    
    printf("\n************* TEST 2:  5 Players (More than allowed) ***************\n");
    
    printf("    Expected result: -1\n");

    //reset variables
    curState = newGame();
    result = 0;
    result = initializeGame(5, k, seed, curState);
    
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
    
    printf("\n**************** TEST 3: Multiples in Kingdom Cards ****************\n");
    
    printf("    Expected result: -1\n");
    
    //reset variables
    curState = newGame();
    result = 0;
    result = initializeGame(2, testK, seed, curState);
    
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
    
    printf("\n************** TEST 4:  Passing all useable variables **************\n");
    
    printf("    Expected result: 0\n");

    //reset variables
    curState = newGame();
    result = 0;
    result = initializeGame(2, k, seed, curState);
    
    if (result == -1) {
        printf("    Actual result  : %d\n",result);
        printf("    FAILED\n");
        //increment fail count
        fCount++;
    }
    else{
        printf("    Actual result  : %d\n",result);
        printf("    PASSED!\n");
    }
    
    printf("\n*************** TEST 5: Confirming number of players ***************\n");
    
    printf("    Expected result: 2\n");
    
    //reset variables
    curState = newGame();
    result = 0;
    result = initializeGame(2, k, seed, curState);
    playerCount = curState->numPlayers;
    
    if (result == 0 && playerCount == 2){
        printf("    Actual result  : %d\n",playerCount);
        printf("    PASSED!\n");
    }
    else {
        printf("    Actual result  : %d\n",playerCount);
        printf("    FAILED\n");
        //increment fail count
        fCount++;
    }
    
    printf("\n**** TEST 6: Confirm correct count of curse cards for 2 players ****\n");
    
    printf("    Expected result: 10\n");
    
    //reset variables
    curState = newGame();
    result = 0;
    result = initializeGame(2, k, seed, curState);
    curseCount = curState->supplyCount[curse];
    
    if (result == 0 && curseCount == 10){
        printf("    Actual result  : %d\n",curseCount);
        printf("    PASSED!\n");
    }
    else {
        printf("    Actual result  : %d\n",curseCount);
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

