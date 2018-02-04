#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
using namespace std;

#ifndef _ASSERTDOMINIONTEST_H
#define _ASSERTDOMINIONTEST_H


int assertStandardDom(int, string);
int assertGameStateDom(int, string, struct gameState*, struct gameState*);
void printGameState(struct gameState *);

#endif
