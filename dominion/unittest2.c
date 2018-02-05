#include "dominion.h"
#include "assertDominionTest.h"
#include "dominion_helpers.h"
#include "rngs.h"


int checkNumHandCards(struct gameState *state)
{
  int expected;
  int returned;
  char msg[] = "Num Cards Failed"
  expected = state->handCount[state->whoseTurn];
  returned = numHandCards(state);

  if(assertStandardDom((expected == returned), msg)) {
    return 1;
  }
  return 0;
}

int main(){
  int p, i, r;
  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
  struct gameState G;
  char msg[] = "initializeGame failed";
  printf ("Simple Fixed Tests\n");



  for(p = 1; p < 5; p++){
    for(i = 0; i < 4; i++){
      memset(&G, 23, sizeof(struct gameState));
      r = initializeGame(p, k, 1, &G);
      if(assertStandardDom((r == 0), msg)){
        printf("Return Requested.. Returning... ");
        return 1;
      }
      G.whoseTurn = i;
      if(checkNumHandCards(&G)){
        printf("Return Requested.. Returning...");
        return 1;
      } 
    }
    printf("Tests passed for %i players", i);
  }
  printf("Tests passed for all number of players");
  return 0;
}
