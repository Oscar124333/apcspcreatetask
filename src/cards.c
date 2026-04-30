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

void card_construct(Card *card, const char *suit, const char *rank_string, uint8_t value_base)
{
    card->suit = suit;
    card->rank_string = rank_string;
    card->value_base = value_base;
    card->drawn = false;    
}

Card** deck_construct(void)
{
    Card **deck = deck_allocate();
    for (int i = 0; i < NUMBER_SUITS; i++)
    {
        for (int j = 0; j < SIZE_SUIT; j++)
        {
            card_construct(&deck[i][j], SUITS[i], RANKS[j], VALUES_RANK[j]);
        }
    }
    return deck;
}