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
    float multiplier;

    int (*value_total)(struct Card*);
} Card;

extern Card test;

Card** deck_allocate(void);
int value_total(Card *card);
void card_construct(Card *card, char *suit, char *rank_string, uint8_t value_base, float mult);
void deck_construct(Card **deck);

#endif