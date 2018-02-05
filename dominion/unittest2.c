#include "dominion.h"
#include "assertDominionTest.h"
#include "dominion_helpers.h"
#include "rngs.h"


int checkNumHandCards(struct gameState *state)
{
  int expected;
  int returned;
  expected = state->handCount[state->whoseTurn];
  returned = numHandCards(post);

  if(assertStandardDom((expected == returned), "A")) return 1;
  return 0;
}

int main(){
  int p;
  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
  struct gameState G;

  printf ("Simple Fixed Tests\n");

  for(p = 1; p < 5; p++){
    for(i = 0; i < 4; i++){
      r = initializeGame(p, k, 1, &G);
      if(assertStandardDom((r == 0), "initializeGame failed")){
        printf("Return Requested.. Returning... ")
        return 1;
      }
      G.whoseTurn = i;
      if(checkNumHandCards(gameState)){
        printf("Return Requested.. Returning...");
        return 1;
      } 
    }
    printf("Tests passed for %i players", i);
  }
  printf("Tests passed for all number of players");
  return 0;
}
