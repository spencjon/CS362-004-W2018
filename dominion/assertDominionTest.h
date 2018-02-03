#ifndef _ASSERTDOMINIONTEST_H
#define _ASSERTDOMINIONTEST_H
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>

bool assertStandardDom(bool, string);
bool assertGameStateDom(bool, string, struct gameState, struct gameState);
#endif
