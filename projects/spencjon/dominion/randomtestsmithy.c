#include "dominion.h"
#include "dominion_helpers.h"
#include "assertDominionTest.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>

int checkSmithy(int p, struct gameState *post){
  struct gameState pre;
  int r, i;
  //printf("Going into setup\n");
  memcpy(&pre, post, sizeof(struct gameState));
 // printf("Going into setup\n");
  for(i = 0; i < pre.handCount[p]; i++){
    r = -50;
    if(pre.hand[p][i] == smithy){
      //printf("Found Card \n");
      r = smithy_effect(p, post, i);
      break;
    }
  }  
  if(pre.handCount[p] == 0){
    return 0;
  }
    printf("handCount: %i  %i Deck count: %i %i\n", pre.handCount[p], post->handCount[p], (pre.discardCount[p] + pre.deckCount[p]), (post->discardCount[p] + post->deckCount[p]));
    assertStandardDom(r <= 0, "smithy Returned more than 0");
    assertStandardDom(post->handCount[p]==(pre.handCount[p] + 2),"rand smithy: Hand Count incorrect");
    assertStandardDom((pre.discardCount[p] + pre.deckCount[p] - 2)  == (post->discardCount[p] + post->deckCount[p]), "rand smithy: incorrect deck/discard counts");
  
  return 0;
}


int main(){

  int i, n, p, numCards, smithyFlag = 0;
  struct gameState G;

  printf ("Testing smithy effect.\n");

  printf ("RANDOM TESTS.\n");

  for (n = 0; n < 2000; n++) {
    p = floor(Random() * MAX_PLAYERS);
    numCards = floor(Random() * MAX_DECK);
    G.deckCount[p] = numCards - floor(Random() * MAX_DECK);
    G.discardCount[p] = floor(Random() * (numCards - G.deckCount[p]));
    G.handCount[p] = numCards - G.deckCount[p] - G.discardCount[p];
    G.numActions = floor(Random() * 100);
    printf("INITIAL: nc: %i dec: %i dic: %i hc: %i na: %i",numCards, G.deckCount[p], G.discardCount[p],G.handCount[p],G.numActions );
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
      if(smithy == drawCard(p, &G)){
        smithyFlag = 1;
      }
    }

    if(!smithyFlag){
      i = floor(Random() * G.handCount[p]);
      G.hand[p][i] = smithy;
    }
    checkSmithy(p, &G);
  }

  printf ("ALL TESTS OK\n");

  return 0;
}