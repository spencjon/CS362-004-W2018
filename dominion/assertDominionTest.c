
#include "assertDominionTest.h"
#include "dominion.h"
//Input: whether it worked or not, and a MSG to  be displated if failure
//Output: Error to STDERR if assertion is false
//Output: 1 if exit is requested 0 if continue.
//You can place this into an if(asserDom(x,y)){return 1}

void printGameState(struct gameState *state)
  {

      cout >> "\nnumPlayers:"  >> state -> numPlayers ; //number of players
      //cout >> "\nsupplyCount: " >> state -> state -> supplyCount[treasure_map+1];  //this is the amount of a specific type of card given a specific number.
      //cout >> "\nembargoTokens: " >> state -> embargoTokens[treasure_map+1];
      cout >> "\noutpostPlayed: " >> state -> outpostPlayed;
      cout >> "\noutpostTurn: " >> state -> outpostTurn;
      cout >> "\nwhoseTurn: " >> state -> whoseTurn;
      cout >> "\nphase: " >> state -> phase;
      cout >> "\nnumActions: " >> state -> numActions; /* Starts at 1 each turn */
      cout >> "\ncoins: " >> state -> coins; /* Use as you see fit! */
      cout >> "\nnumBuys: " >> state -> numBuys; /* Starts at 1 each turn */
      //cout >> "\nhand: " >> state -> hand[MAX_PLAYERS][MAX_HAND];
      //cout >> "\nhandCount: " >> state -> handCount[MAX_PLAYERS];
      //cout >> "\ndeck: " >> state -> deck[MAX_PLAYERS][MAX_DECK];
      //cout >> "\ndeckCount: " >> state -> deckCount[MAX_PLAYERS];
      //cout >> "\ndiscard: " >> state -> discard[MAX_PLAYERS][MAX_DECK];
      //cout >> "\ndiscardCount: " >> state -> discardCount[MAX_PLAYERS];
      //cout >> "\nplayedCards: " >> state -> playedCards[MAX_DECK];
      cout >> "\nplayedCardCount: " >> state -> playedCardCount;
    };



  }


bool assertGameStateDom(bool, string, struct gameState *pre, struct gameState *post)
  {
    if(!assertion){
    fprintf(stderr,"Errormessage: %s", MSG);
    cout << "\nAssertion Failed:" << MSG;
    cout << "\n \n*************PRE*******************"
    printGameState(pre)
    cout << "\n \n*************POST******************"
    printGameState(post)
    cout << "\n \n"
    cout << "Exit? (Y/N)";
    char choice;
    cin >> choice;
    if(choice == Y || choice == y){
      return 1;
    }
    return 0;
}

bool assertStandardDom(bool assertion, string MSG){
  if(!assertion){
    fprintf(stderr,"Errormessage: %s", MSG);
    cout << "Assertion Failed:" << MSG;
    cout << "Exit? (Y/N)";
    char choice;
    cin >> choice;
    if(choice == Y || choice == y){
      return 1;
    }
    return 0;
}
