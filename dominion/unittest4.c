#include <string.h>
#include "dominion.h"
#include "assertDominionTest.h"
#include "dominion_helpers.h"
#include "rngs.h"

int checkIsGameOver(struct gameState* state) {
    int i, j, expected = 1, returned;  
    struct gameState modify = *state;
    
    returned = isGameOver(&modify);  
    
    if(assertStandardDom((expected == returned), "Just Initialized")){
        return 1;
    }

    modify.supplyCount[province] = 0;
    returned = isGameOver(&modify);  
    if(assertStandardDom((expected == returned), "Provinces == 0")){
        return 1;
    }

    modify.supplyCount[province] = 2;
    modify.supplyCount[smithy] = 0;
    modify.supplyCount[adventurer] = 0;
    modify.supplyCount[great_hall] = 0;
    returned = isGameOver(&modify);  
    if(assertStandardDom((expected == returned), "3 supply piles are empy")){
        return 1;
    }

    printf("Tests passed");
    return 0;
}

int main(){
  int r, i, p;
  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};
  struct gameState G;

  printf ("Simple Fixed Tests\n");

  for(p = 2; p < 5; p++){
      r = initializeGame(p, k, 1, &G);
      if(assertStandardDom((r == 0), "initializeGame failed")){
        printf("Return Requested.. Returning... ");
        return 1;
      }
      G.whoseTurn = i;
      if(checkIsGameOver(&G)){
        printf("Return Requested.. Returning...");
        return 1;
    }
    printf("Tests passed for %i players", i);
  }
  printf("Tests passed for all number of players");
  return 0;
}