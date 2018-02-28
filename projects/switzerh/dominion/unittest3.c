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
    
    //int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron};
    //int testK[10] = {adventurer, adventurer, feast, feast, mine, remodel, smithy, village, baron};
    
    //int seed = 2;
    //int curseCount = 0;
    //int playerCount = 0;
    int result = 0;
    int fCount = 0;
    
    curState = newGame();
    printf("\n********************************************************************\n");
    printf("********************************************************************\n\n");
    printf("                            UNIT TEST 3                             \n");
    printf("                 Testing Function: isGameOver()                 \n\n");
    printf("********************************************************************\n");
    printf("********************************************************************\n\n\n");
    
    printf("********************* TEST 1: 3 provinces left *********************\n");
    
    curState->supplyCount[province]=3;
    for (int i=0; i<25; i++){
        curState->supplyCount[i]=1;
    }
    result = isGameOver(curState);
    
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
    
    printf("********************* TEST 2: 0 provinces left *********************\n");
    
    curState->supplyCount[province] = 0;
    result = isGameOver(curState);
    
    printf("    Expected result: 1\n");
    
    if (result == 1) {
        printf("    Actual result  : %d\n",result);
        printf("    PASSED!\n");
    }
    else{
        printf("    Actual result  : %d\n",result);
        printf("    FAILED\n");
        //increment fail count
        fCount++;
    }
    
    printf("********************* TEST 3: -1 provinces left *********************\n");
    
    curState->supplyCount[province] = -1;
    result = isGameOver(curState);
    
    printf("    Expected result: 1\n");
    
    if (result == 1) {
        printf("    Actual result  : %d\n",result);
        printf("    PASSED!\n");
    }
    else{
        printf("    Actual result  : %d\n",result);
        printf("    FAILED\n");
        //increment fail count
        fCount++;
    }
    
    printf("*********************** TEST 4: 3 empty piles ***********************\n");
    
    curState->supplyCount[province] = 3;
    for (int i=0; i<3; i++){
        curState->supplyCount[i]=0;
    }
    result = isGameOver(curState);
    
    printf("    Expected result: 1\n");
    
    if (result == 1) {
        printf("    Actual result  : %d\n",result);
        printf("    PASSED!\n");
    }
    else{
        printf("    Actual result  : %d\n",result);
        printf("    FAILED\n");
        //increment fail count
        fCount++;
    }
    
    printf("*********************** TEST 5: Negative supply count ***********************\n");
    
    curState->supplyCount[province] = 3;
    for (int i=0; i<3; i++){
        curState->supplyCount[i]=-1;
    }
    result = isGameOver(curState);
    
    printf("    Expected result: 1\n");
    
    if (result == 1) {
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


