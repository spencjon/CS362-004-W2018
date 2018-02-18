#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int checkAdventurer(int p, struct gameState *post){
struct gameState pre;
  memcpy (&pre, post, sizeof(struct gameState));
  int r, i, numTreasure;
    
  r = adventurer_effect(post, p);
  
  assert (r == 0);
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
  

  if(numTreasure > 1){
    assert((pre.handCount[p]+1) == post->handCount[p]);
    assert(post->hand[p][post->handCount-1] == copper || post->hand[p][post->handCount-1] == silver || post->hand[p][post->handCount-1] == gold);
    assert(post->hand[p][post->handCount-2] == copper || post->hand[p][post->handCount-2] == silver || post->hand[p][post->handCount-2] == gold);
  } else if(numTreasure == 1){
    assert(pre.handCount[p] == post->handCount[p]);
    assert(pre.deckCount[p] - post->deckCount);
    assert(post->hand[p][post->handCount-1] == copper || post->hand[p][post->handCount-1] == silver || post->hand[p][post->handCount-1] == gold);
  }else{
    assert((pre.handCount[p]-1) == post->handCount[p]);
  }
  assert((pre.playedCardCount+1) == post->playedCardCount);
  assert((pre.deckCount[p] - post->deckCount[p]) == (post->discardCount[p] - pre.discardCount[p] - 1));
}

int main(){

  int i, j, n, r, p, deckCount, discardCount, handCount;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

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
    for(j = 0; j < G.deckCount[p]; j++){
        G.deck[p][j] = floor(Random() * treasure_map);
    }
    checkAdventurer(p, &G);
  }

  printf ("ALL TESTS OK\n");





}