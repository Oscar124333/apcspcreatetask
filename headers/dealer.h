#ifndef dealer_H
#define dealer_H

#include "constants.h"
#include "cards.h"

#include <stdlib.h>
#include <time.h>

int* list_RNG(int length, int rangeStart, int rangeEnd);
Card* hand_generate(Card **deck, int handSize);

#endif