#include "dominion.h"
#include "dominion_helpers.h"
#include "assertDominionTest.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>

int checkVillage(int p, struct gameState *post){
    struct gameState pre;
  int preHandTreasure, postHandTreasure;
  int r, i, numTreasure, handPos = -50;

  //printf("Going into setup\n");
  memcpy(&pre, post, sizeof(struct gameState));
 // printf("Going into setup\n");
  for(i = 0; i < pre.handCount[p]; i++){
    r = -50;
    if(pre.hand[p][i] == village){
      //printf("Found Card \n");
      r = village_effect(p, post, i);
      handPos = i;
      break;
    }
  }  
  if(pre.handCount[p] == 0){
    return 0;
  }

  assertStandardDom(r == 0, "village Returned not 0");
  
  preVillageCount = 0;
  postVillageCount = 0;
  for(i = 0; i < pre.handCount[p]; i++){
    if(pre.hand[p][i] == copper || pre.hand[p][i] == silver || pre.hand[p][i] == gold){
      preVillageCount++;
    }
  }
  for(i = 0; i < post->handCount[p]; i++){
    if(post->hand[p][i] == village){
      postVillageCount++;
    }
  }

    assertStandardDom(post->handCount[p]==pre.handCount[p],"rand village: Hand Count incorrect");
    assertStandardDom(pre.numActions = post->numActions+2, "rand village: number of actions incorrect");
    assertStandardDom((pre.discardCount[p]+1) = post.discardCount[p], "rand village: discard count incorrect");
    assertStandardDom((pre.deckCount))
  }
  return 0;
}


int main(){

  int i, n, p, numCards, villageFlag = 0;
  struct gameState G;

  printf ("Testing villager effect.\n");

  printf ("RANDOM TESTS.\n");

  for (n = 0; n < 2000; n++) {
    p = floor(Random() * MAX_PLAYERS);
    numCards = floor(Random() * MAX_DECK)
    G.deckCount[p] = numCards - floor(Random() * MAX_DECK);
    G.discardCount[p] = floor(Random() * (numCards - G.deckCount[p]);
    G.handCount[p] = numCards - G.deckCount[p] - G.discardCount[p];
    if(G.handCount[p] < 1){
        G.handCount[p] = 1;
        if(G.discardCount[p] < 1)
            G.discardCount[p]--;
        else 
            G.deckCount[p]--;
    }
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