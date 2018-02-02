#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include "cards.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int smithy(int currentPlayer, struct gameState *state, int handPos){ //draw 3 cards
    for (int i = 0; i < 3; i++)
	{
	  drawCard(currentPlayer, state);
	}
			
      //discard card from hand
      discardCard(handPos, currentPlayer, state, 0);
      return 0;
}

int adventurer(int drawntreasure, struct gameState *state, int currentPlayer){
    while(drawntreasure<2){
        if (state->deckCount[currentPlayer] <1){//if the deck is empty we need to shuffle discard and add to deck
            shuffle(currentPlayer, state);
        }
        drawCard(currentPlayer, state);
        cardDrawn = state->hand[currentPlayer][state->handCount[currentPlayer]-1];//top card of hand is most recently drawn card.
        if (cardDrawn == copper || cardDrawn == silver || cardDrawn == gold)
            drawntreasure++;
        else{
            temphand[z]=cardDrawn;
            state->handCount[currentPlayer]--; //this should just remove the top card (the most recently drawn one).
            z++;
        }
    }
    while(z-1>=0){
        state->discard[currentPlayer][state->discardCount[currentPlayer]++]=temphand[z-1]; // discard all cards in play that have been drawn
        z=z-1;
    }
    return 0;
}

int village(int currentPlayer, struct gameState *state, int handPos){
//+1 Card
    drawCard(currentPlayer, state);
        
    //+2 Actions
    state->numActions = state->numActions + 2;
        
    //discard played card from hand
    discardCard(handPos, currentPlayer, state, 0);
    return 0;
}

int baron(int currentPlayer, struct gameState *state, int handPos, int choice1){
    state->numBuys++;//Increase buys by 1!
      if (choice1 > 0){//Boolean true or going to discard an estate
	int p = 0;//Iterator for hand!
	int card_not_discarded = 1;//Flag for discard set!
	while(card_not_discarded){
	  if (state->hand[currentPlayer][p] == estate){//Found an estate card!
	    state->coins += 4;//Add 4 coins to the amount of coins
	    state->discard[currentPlayer][state->discardCount[currentPlayer]] = state->hand[currentPlayer][p];
	    state->discardCount[currentPlayer]++;
	    for (;p < state->handCount[currentPlayer]; p++){
	      state->hand[currentPlayer][p] = state->hand[currentPlayer][p+1];
	    }
	    state->hand[currentPlayer][state->handCount[currentPlayer]] = -1;
	    state->handCount[currentPlayer]--;
	    card_not_discarded = 0;//Exit the loop
	  }
	  else if (p > state->handCount[currentPlayer]){
	    if(DEBUG) {
	      printf("No estate cards in your hand, invalid choice\n");
	      printf("Must gain an estate if there are any\n");
	    }
	    if (supplyCount(estate, state) > 0){
	      gainCard(estate, state, 0, currentPlayer);
	      state->supplyCount[estate]--;//Decrement estates
	      if (supplyCount(estate, state) == 0){
		isGameOver(state);
	      }
	    }
	    card_not_discarded = 0;//Exit the loop
	  }
			    
	  else{
	    p++;//Next card
	  }
	}
      }
			    
      else{
	if (supplyCount(estate, state) > 0){
	  gainCard(estate, state, 0, currentPlayer);//Gain an estate
	  state->supplyCount[estate]--;//Decrement Estates
	  if (supplyCount(estate, state) == 0){
	    isGameOver(state);
	  }
	}
      }
    return 0;
}

int council_room(int currentPlayer, struct gameState *state, int handPos){
    //+4 Cards
      for (int i = 0; i < 4; i++)
	{
	  drawCard(currentPlayer, state);
	}
			
      //+1 Buy
      state->numBuys++;
			
      //Each other player draws a card
      for (int i = 0; i < state->numPlayers; i++)
	{
	  if ( i != currentPlayer )
	    {
	      drawCard(i, state);
	    }
	}
			
      //put played card in played card pile
      discardCard(handPos, currentPlayer, state, 0);

      return 0;
}


//end of cards.c