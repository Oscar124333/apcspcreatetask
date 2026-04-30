#ifndef constants_H
#define constants_H

#include <stdint.h>

// True/false macro
#define false 0
#define true 1
#define EXIT 9

// Basic 52-card deck definitions
extern const uint8_t NUMBER_SUITS;
extern const uint8_t SIZE_SUIT;
extern const uint8_t SIZE_DECK;

extern const char *SUITS[];
extern const char *RANKS[];
extern const uint8_t VALUES_RANK[];

// Other Constants
extern const uint8_t NULL_TERM;
#endif