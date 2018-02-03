#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

#ifndef _ASSERTDOMINIONTEST_H
#define _ASSERTDOMINIONTEST_H


bool assertStandardDom(bool, string);
bool assertGameStateDom(bool, string, struct gameState, struct gameState);
#endif
