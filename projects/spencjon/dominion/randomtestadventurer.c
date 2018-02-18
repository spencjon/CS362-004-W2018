#include "dominion.h"
#include "dominion_helpers.h"
#include "assertDominionTest.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <math.h>

int checkAdventurer(int p, struct gameState *post){
struct gameState pre;
int preHandTreasure, postHandTreasure;
  memcpy (&pre, post, sizeof(struct gameState));
  int r, i, numTreasure, handPos = -50;
  for(i = 0; i < pre.handCount[p]; i++){
    if(pre.hand[p][i] == adventurer){
      r = adventurer_effect(post, p, i);
      handPos = i;
      break;
    }
  }  

  if(pre.handCount[p] == 0){
    return 0;
  }
  if(handPos == -50){
    printf("No Adventurer\n");
    return 0;
  }

  assertStandardDom(r == 0, "Adventurer Returned not 0");
  numTreasure = 0;
  for(i = 0; i < pre.deckCount[p]; i++){
      if(pre.deck[p][i] == copper || pre.deck[p][i] == silver || pre.deck[p][i] == gold){
          numTreasure++;
      }
  }
  for(i = 0; i < pre.discardCount[p]; i++){
      if(pre.discard[p][i] == copper || pre.discard[p][i] == silver || pre.discard[p][i] == gold){
          numTreasure++;
      }
  }
  preHandTreasure = 0;
  postHandTreasure = 0;
  for(i = 0; i < pre.handCount[p]; i++){
    if(pre.hand[p][i] == adventurer){
      preHandTreasure++;
    }
  }
  for(i = 0; i < post->handCount[p]; i++){
    if(post->hand[p][i] == adventurer){
      postHandTreasure++;
    }
  }

  if(numTreasure > 1){
    printf("HandCount Post: %i, Pre %i \n",post->handCount[p],pre.handCount[p]);
    printf("TreasureDelta: Post %i, PRe %i \n", postHandTreasure, preHandTreasure);
    assertStandardDom(((pre.handCount[p]) + 1) == (post->handCount[p]), "Hand Counts inequal, enough treasure.");
    assertStandardDom(((postHandTreasure - 2) == preHandTreasure), "Incorrect Number of pre/post hand treasure delta");
  } else if(numTreasure == 1){
    assertStandardDom(pre.handCount[p] == post->handCount[p], "Hand Counts inequal, one treasure.");
    assertStandardDom(((postHandTreasure - 1) == preHandTreasure), "Incorrect Number of pre/post hand treasure delta");
  }else{
    assertStandardDom((pre.handCount[p]-1) == post->handCount[p], "Hand Counts inequal, no treasure.");
  }
  return 0;
}

int main(){

  int i, n, p, adventurerFlag = 0;
  struct gameState G;

  printf ("Testing drawCard.\n");

  printf ("RANDOM TESTS.\n");

  SelectStream(2);
  PutSeed(3);

  for (n = 0; n < 2000; n++) {
    for (i = 0; i < sizeof(struct gameState); i++) {
      ((char*)&G)[i] = floor(Random() * 256);
    }
    p = floor(Random() * 2);
    G.deckCount[p] = floor(Random() * MAX_DECK);
    G.discardCount[p] = floor(Random() * MAX_DECK);
    G.handCount[p] = floor(Random() * MAX_HAND);
    for(i = 0; i < G.deckCount[p]; i++){
        G.deck[p][i] = floor(Random() * treasure_map);
    }
    for(i = 0; i < G.discardCount[p]; i++){
      G.discard[p][i] = floor(Random() * treasure_map);
    }
    for(i = 0; i < G.handCount[p]; i++){
      if(adventurer == drawCard(p, &G)){
        adventurerFlag = 1;
      }
    }
    if(!adventurerFlag){
      i = floor(Random() * G.handCount[p]);
      if(i == G.handcount[p]){
        i--;
      }
      G.hand[p][i] = adventurer;
    }
    printf("%i) ", n);
    checkAdventurer(p, &G);
  }

  printf ("ALL TESTS OK\n");

  return 0;
}