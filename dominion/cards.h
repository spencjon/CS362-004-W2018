#ifndef _CARDS_H
#define _CARDS_H

int smithy(int currentPlayer, struct gameState *state, int handPos); //
int adventurer(int drawntreasure, struct gameState *state, int currentPlayer); //
int village(int currentPlayer, struct gameState *state, int handPos); //
int baron(int currentPlayer, struct gameState *state, int handPos, int choice1); //
int council_room(int currentPlayer, struct gameState *state, int handPos); //

#endif