#include "dominion.h"
#include "dominion_helpers.h"
#include "assertDominionTest.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>

int main(){
 int i, n, p, villageFlag = 0;
  struct gameState G;

  printf ("Testing smithy effect.\n");

  printf ("RANDOM TESTS.\n");

  for (n = 0; n < 2000; n++) {
    p = floor(Random() * MAX_PLAYERS);
    G.deckCount[p] = floor(Random() * MAX_DECK);
    G.discardCount[p] = floor(Random() * MAX_DECK);
    G.handCount[p] = floor(Random() * MAX_HAND);
    G.playedCardCount = 0;
    for(i = 0; i < G.deckCount[p]; i++){
        G.deck[p][i] = floor(Random() * treasure_map);
    }

    for(i = 0; i < G.discardCount[p]; i++){
      G.discard[p][i] = floor(Random() * treasure_map);
    }

    for(i = 0; i < G.handCount[p]; i++){
      if(village == drawCard(p, &G)){
        villageFlag = 1;
      }
    }

    if(!villageFlag){
      i = floor(Random() * G.handCount[p]);
      G.hand[p][i] = village;
    }
    checkVillage(p, &G);
  }

  printf ("ALL TESTS OK\n");

  return 0;
}