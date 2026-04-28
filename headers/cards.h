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
    _Bool drawn;

    int (*value_total)(struct Card*);
} Card;

int value_total(Card *card);
Card** deck_allocate(void);
void card_construct(Card *card, char *suit, char *rank_string, uint8_t value_base);
Card** deck_construct(void);

#endif