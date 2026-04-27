#include "cards.h"
#include "constants.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Card Functions

Card** deck_allocate(void)
{
    Card **ptrDeck = malloc(sizeof(Card) * NUMBER_SUITS);
    if (ptrDeck == NULL)
    {
        free(ptrDeck);
        perror("Suit malloc");
        return NULL;
    }

    for (int i = 0; i < NUMBER_SUITS; i++)
    {
        ptrDeck[i] = malloc(sizeof(Card) * SIZE_SUIT);
        if (ptrDeck[i] == NULL)
        {
            free(ptrDeck[i]);
            perror("Suit malloc");
            return NULL;
        }
    }
    return ptrDeck;
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