#include "cards.h" 
#include <stdint.h>

int value_total(Card* card)
{
    int output = card->value_base * card->multiplier;
    return output;
}

void card_construct(Card* card, char *rank_string, char *suit, uint8_t value_base, float mult)
{
    card->rank_string = rank_string;
    card->suit = suit;
    card->value_base = value_base;
    card->multiplier = mult;
    card->value_total = value_total;
}

// void deck_construct(Card** cards)
// {
//     for (int i = 0; i < SIZE_DECK; i++)
//     {
//         card_construct(cards[i])
//     }
// }

// Basic 52-card deck definitions
const uint8_t SIZE_SUIT = 13;
const uint8_t NUMBER_SUITS = 4;
const uint8_t SIZE_DECK = SIZE_SUIT * NUMBER_SUITS; 

const char *SUITS[] =
    {"Spades", "Hearts", "Clubs", "Diamonds"};

const char *RANKS[] =
    {"2", "3", "4", "5", "6", "7", "8", "9", "10",
    "Jack", "Queen", "King", "Ace"};

const uint8_t VALUES_CARD[] =
    {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};
    // 2-10 (2-10), Face x3 (10), Ace (11)