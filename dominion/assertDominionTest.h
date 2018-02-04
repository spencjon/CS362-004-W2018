#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

#ifndef _ASSERTDOMINIONTEST_H
#define _ASSERTDOMINIONTEST_H


bool assertStandardDom(bool, string);
bool assertGameStateDom(bool, string, struct gameState*, struct gameState*);
void printGameState(struct gameState *);

#endif
