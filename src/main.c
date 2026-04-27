#include "constants.h"
#include "cards.h"
#include "dealer.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));

    Card **playerDeck = deck_allocate();
    if (playerDeck == NULL) {return -1;}

    deck_construct(playerDeck);

    /* debug */
    // for (int i = 0; i < NUMBER_SUITS; i++)
    // {
    //     printf("\nSuit: %s\n", SUITS[i]);
    //     for (int j = 0; j < SIZE_SUIT; j++)
    //     {
    //         printf("Rank: %s, Value: %d\n", playerDeck[i][j].rank_string, playerDeck[i][j].value_base);
    //     }
    // }
    /* end */

    hand_generate();

    return 0;
}
