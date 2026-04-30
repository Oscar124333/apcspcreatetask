#ifndef cards_H
#define cards_H 

#include "constants.h"

#include <stdint.h>

// Card Functions

typedef struct Card
{
    char *suit;
    char *rank_string;
    uint8_t value_base;
    _Bool drawn;
} Card;

Card** deck_allocate(void);
void card_construct(Card *card, const char *suit, const char *rank_string, uint8_t value_base);
Card** deck_construct(void);

#endif