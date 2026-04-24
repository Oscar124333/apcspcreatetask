#ifndef cards_H
#define cards_H 

#include <stdint.h>
#include <stdbool.h>

// Basic 52-card deck definitions
extern const uint8_t NUMBER_SUITS;
extern const uint8_t SIZE_SUIT;
extern const uint8_t SIZE_DECK;

extern const char *SUITS[];
extern const char *RANKS[];
extern const uint8_t VALUES_RANK[];

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

bool deck_allocate(Card **deck);
int value_total(Card *card);
void card_construct(Card *card, char *suit, char *rank_string, uint8_t value_base, float mult);
void deck_construct(Card **deck);

#endif