#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "cards.h"

int main(void)
{
    Card *playerDeck = malloc(sizeof(Card) * SIZE_DECK);

    card_construct(&playerDeck[0], "King", "Clubs", 10, 1.5);
    int x = playerDeck[0].value_total(&playerDeck[0]);

    printf("suit: %s\n", playerDeck[0].suit);
    printf("total: %d\n", x);

    return 0;
}
