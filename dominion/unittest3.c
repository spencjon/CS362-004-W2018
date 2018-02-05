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
    char msg[] = "Too many Estate, Dutchy, or Province";
    returnedCount = whoseTurn(state);
    expectedCount = state->supplyCount[card];
    msg = "CheckSupplyCount, not equal";
    if(assertStandardDom((int)(returnedCount == expectedCount), msg)) return 1;
    numPlayers = state->numPlayers;
    if(numPlayers < 3)
      if(card >= 1 && card <= 3)
          if(assertStandardDom((expectedCount > 8), msg)) return 1;
  return 0;
}


int main(){
  int p;
  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
  struct gameState G;
  char msg[] = "initializeGame failed";
  printf ("Simple Fixed Tests\n");

  for(p = 1; p < 5; p++){
    for(i = 0; i < 4; i++){
      r = initializeGame(p, k, 1, &G);
      if(assertStandardDom((r == 0), msg){
        printf("Return Requested.. Returning... ")
        return 1;
      }
      if(checkSupplyCount(gameState)){
        printf("Return Requested.. Returning...");
        return 1;
      } 
    }
    printf("Tests passed for %i players", i);
  }
  printf("Tests passed for all number of players");
  return 0;
}