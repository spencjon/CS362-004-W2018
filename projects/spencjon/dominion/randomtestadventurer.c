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
  printf("Going into setup");
  memcpy (&pre, post, sizeof(struct gameState));
  int r, i, numTreasure, handPos = -50;
  for(i = 0; i < pre.handCount[p]; i++){
    if(pre.hand[p][i] == adventurer){
      r = adventurer_effect(post, p, i);
      handPos = i;
      break;
    }
  }  
  printf("Past setup");
  if(pre.handCount[p] == 0){
    return 0;
  }
  if(handPos == -50){
    printf("No Adventurer\n");
    return 0;
  }
  printf("Past %s \n", "incompatible arguments");
  assertStandardDom(r == 0, "Adventurer Returned not 0");
  numTreasure = 0;
  for(i = 0; i < pre.deckCount[p]; i++){
      if(pre.deck[p][i] == copper || pre.deck[p][i] == silver || pre.deck[p][i] == gold){
          numTreasure++;
      }
  }
  printf("Past %s \n", "deck num treasuer");

  for(i = 0; i < pre.discardCount[p]; i++){
      if(pre.discard[p][i] == copper || pre.discard[p][i] == silver || pre.discard[p][i] == gold){
          numTreasure++;
      }
  }
  printf("Past %s \n", "discard num treasuer");

  preHandTreasure = 0;
  postHandTreasure = 0;
  for(i = 0; i < pre.handCount[p]; i++){
    if(pre.hand[p][i] == adventurer){
      preHandTreasure++;
    }
  }
  printf("Past %s \n", "prehand num treasuer");

  for(i = 0; i < post->handCount[p]; i++){
    if(post->hand[p][i] == adventurer){
      postHandTreasure++;
    }
  }
  printf("Past %s \n", "posthand num treasuer");

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

  printf ("Testing adventurer effect.\n");

  printf ("RANDOM TESTS.\n");

  for (n = 0; n < 2000; n++) {
    p = floor(Random() * MAX_PLAYERS);
    printf("1\n");
    G.deckCount[p] = floor(Random() * MAX_DECK);
    printf("2\n");
    G.discardCount[p] = floor(Random() * MAX_DECK);
    printf("3\n");
    G.handCount[p] = floor(Random() * MAX_HAND);
    //G.deck = (int**)malloc((p+1) *sizeof(int*));
    //G.deck[p] = (int**)malloc(MAX_DECK * sizeof(int)); 
    printf("1testing adventurer\n");

    for(i = 0; i < G.deckCount[p]; i++){
        G.deck[p][i] = floor(Random() * treasure_map);
    }
    //G.discard = (int[MAX_PLAYERS][MAX_DECK])malloc((p+1) *sizeof(int*));
    //G.discard[p] = (int[MAX_DECK])malloc(MAX_DECK * sizeof(int)); 
    printf("2testing adventurer\n");

    for(i = 0; i < G.discardCount[p]; i++){
      G.discard[p][i] = floor(Random() * treasure_map);
    }
    //G.hand = (int**)malloc((p+1) *sizeof(int*));
    //G.hand[p] = (int**)malloc(MAX_HAND * sizeof(int)); 
    printf("3testing adventurer\n");

    for(i = 0; i < G.handCount[p]; i++){
      if(adventurer == drawCard(p, &G)){
        adventurerFlag = 1;
      }
    }
    printf("4testing adventurer\n");

    if(!adventurerFlag){
      i = floor(Random() * G.handCount[p]);
      if(i == G.handCount[p]){
        i--;
      }
      G.hand[p][i] = adventurer;
    }
    printf("5testing adventurer\n");
    checkAdventurer(p, &G);
  }

  printf ("ALL TESTS OK\n");

  return 0;
}