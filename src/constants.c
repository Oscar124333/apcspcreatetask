#include "constants.h"

#include <stdint.h>

// Basic 52-card deck definitions
const uint8_t NUMBER_SUITS = 4;
const uint8_t SIZE_SUIT = 13;
const uint8_t SIZE_DECK = SIZE_SUIT * NUMBER_SUITS; 

const char *SUITS[] =
    {"Spades", "Hearts", "Clubs", "Diamonds"};

const char *RANKS[] =
    {"2", "3", "4", "5", "6", "7", "8", "9", "10",
    "Jack", "Queen", "King", "Ace"};

const uint8_t VALUES_RANK[] =
    {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};
    // 2-10 (2-10), Face x3 (10), Ace (11)

// Other Constants
const uint8_t NULL_TERM = 1;