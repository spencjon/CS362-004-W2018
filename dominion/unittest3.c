#include <string.h>
#include "dominion.h"
#include "assertDominionTest.h"
#include "dominion_helpers.h"
#include "rngs.h"

/*

int supplyCount(int card, struct gameState *state) {
  return state->supplyCount[card];
}

*/


int checkSupplyCount(int card, struct gameState* state) {
    int expectedCount, returnedCount, numPlayers;
    char msg1[] = "Too many Estate, Dutchy, or Province";
    char msg2[] = "CheckSupplyCount, not equal";
    returnedCount = whoseTurn(state);
    expectedCount = state->supplyCount[card];
    printf("tmp 4");
    if(assertStandardDom((int)(returnedCount == expectedCount), msg1)){
      return 1;
    }

    numPlayers = state->numPlayers;
    if(numPlayers < 3){
      if(card >= 1 && card <= 3){
        if(assertStandardDom((expectedCount > 8), msg2)){ 
          return 1;
        }
      }
    }
  return 0;
}


int main(){
  int p, i, r;
  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
  struct gameState G;
  char msg1[] = "initializeGame failed";
  printf ("Simple Fixed Tests\n");

  for(p = 1; p < 5; p++){
    for(i = 0; i < 27; i++){
      r = initializeGame(p, k, 1, &G);
      if(assertStandardDom((r == 0), msg1)){
        printf("Return Requested.. Returning... \n");
        return 1;
      }
      printf("tmp 1");
      if(checkSupplyCount(i, &G)){
        printf("Return Requested.. Returning... card number: %i \n", i);
        return 1;
      }
      printf("tmp 2"); 
    }
    printf("Tests passed for %i cards\n", i);
  }
  printf("Tests passed for all number of players\n");
  return 0;
}