#include "cards.h" 
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Card Functions

bool deck_allocate(Card **deck)
{
    Card **ptrSuit = malloc(sizeof(Card) * NUMBER_SUITS);
    if (ptrSuit == NULL)
    {
        free(ptrSuit);
        perror("Suit malloc");
        return false;
    }

    deck = ptrSuit;
    for (int i = 0; i < NUMBER_SUITS; i++)
    {
        Card *ptrCard = malloc(sizeof(Card) * SIZE_SUIT);
        if (ptrCard == NULL)
        {
            free(ptrCard);
            perror("Suit malloc");
            return false;
        }
        deck[i] = ptrCard;
    }
    return true;
}

int value_total(Card *card)
{
    int output = card->value_base * card->multiplier;
    return output;
}

void card_construct(Card *card, char *suit, char *rank_string, uint8_t value_base, float mult)
{
    card->suit = suit;
    card->rank_string = rank_string;
    card->value_base = value_base;
    card->multiplier = mult;
    
    card->value_total = value_total;
}

void deck_construct(Card **deck)
{
    for (int i = 0; i < NUMBER_SUITS; i++)
    {
        for (int j = 0; j < SIZE_SUIT; j++)
        {
            card_construct(&deck[i][j], SUITS[i], RANKS[j], VALUES_RANK[j], 1);
        }
    }
}