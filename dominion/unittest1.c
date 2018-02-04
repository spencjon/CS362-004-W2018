//testDiscardCard.c
#include "dominion.h"
#include "dominion_helpers.h"
#include "assertDominionTest.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <string>
#include <cstring>

#define DEBUG 0
#define NOISY_TEST 1

int checkDiscardCard(int hp, int tf, int p, struct gameState *post) {
  struct gameState pre;
  memcpy (&pre, post, sizeof(struct gameState));

  int r;
  //  printf ("discardCard PRE: p %d HC %d DeC %d DiC %d\n",
  //	  p, pre.handCount[p], pre.deckCount[p], pre.discardCount[p]);

  r = discardCard(hp,p, &post,tf);

  //printf ("drawCard POST: p %d HC %d DeC %d DiC %d\n",
  //      p, post->handCount[p], post->deckCount[p], post->discardCount[p]);
  if(tf < 1)
    {
      pre.playedCards[pre.playedCardCount] = pre.hand[p][hp];
      pre.playedCardCount++;
      if(assertGameStateDom(pre.playedCardCount == post->playedCardCount, "CheckDiscardCard Trash Flag", &pre, post))
      {
        return 1;
      }
    }
  pre.hand[p][hp] = -1;
  if(hp == (pre.handCount[p] -1) )
    {
      pre.handCount[p]--;
    }
  else if ( pre. handCount[p] == 1 )
    {
      pre.handCount[p]--;
    }
  else
    {
      pre.hand[p][hp] = pre.hand[p][pre.handCount[p] -1];
      pre.hand[p][pre.handCount[p] -1] = -1;
      prre.handCount[p]--;
    }

  if(assertStandardDom(r == 0, "CheckDiscardCard Asserting R -eq 0"))
  {
    return 1;
  }

  if(assertGameStateDom(memcmp(&pre, post, sizeof(struct gameState)) == 0, "CheckDiscardCard Final Assertion Gamestate equal", &pre, post))
  {
    return 1;
  }
}
