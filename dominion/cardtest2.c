#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include "assertDominionTest.h"

int checkAdventurerCard(int currentPlayer, struct gameState* gameReturned, struct gameState* gameExpected){
  int checkSmithyCard(int currentPlayer, struct gameState* gameReturned){
    
    int returned;
    struct gameState gameExpected;
    memcpy (&gameExpected, gameReturned, sizeof(struct gameState));
    returned = playCard(0,1,1,1,gameReturned);
    
    if(assertStandardDom(returned == -1, "Play Card Failed")){
        return 1;
    }

    gameExpected.handCount[currentPlayer] += 1;
    gameExpected.deckCount[currentPlayer] -= 1;
    printf("HandCount1: %i     2: %i    DeckCount1: %i      2: %i      \n", gameExpected.handCount[currentPlayer], gameReturned->handCount[currentPlayer], gameExpected.deckCount[currentPlayer], gameReturned->deckCount[currentPlayer] );
    if (assertStandardDom(gameReturned->deckCount[currentPlayer] == gameExpected.deckCount[currentPlayer], "Deck Count Varies")){
        return 1;
    }
    if (assertStandardDom(gameReturned->handCount[currentPlayer] == gameExpected.handCount[currentPlayer], "Hand Count Varies")){
        return 1;
    }

    cardDrawn1 = gameReturned->hand[currentPlayer][gameReturned->handCount[currentPlayer]-1];
    cardDrawn2 = gameReturned->hand[currentPlayer][gameReturned->handCount[currentPlayer]-2];
    if(assertStandardDom(cardDrawn1 != copper && cardDrawn1 != silver && cardDrawn1 != gold, "Did not draw a treasure first")){
        return 1;    
    }
     if(assertStandardDom(cardDrawn2 != copper && cardDrawn2 != silver && cardDrawn2 != gold, "Did not draw a treasure second")){
        return 1;    
    }
    return 0;
}


int main () {

  int p, i;

  int k[10] = {adventurer, council_room, feast, gardens, mine,
	       remodel, smithy, village, baron, great_hall};

  struct gameState G;

  printf ("SIMPLE FIXED TESTS: Adventurer Card\n");
  for (p = 2; p < 5; p++)
  {
    for(i = 0; i < p; i++)
    {
        printf("Testing Players: %i, Player: %i\n", p, i);
        initializeGame(2, k, 1, &G);
        G.hand[i][0] = 7; //place adventurer card into hand
        G.whoseTurn = i; //it's that person's turn
        
        if(checkAdventurerCard(i, &G))
        {
            printf("\n****ERROR: Tests Failed, requeted return****\n");
            return 1;
        } 
    }
    printf("\nTest for numPlayers = %i has passed\n", p);
  }
  printf("\nAll tests have passed\n");

  return 0;
}