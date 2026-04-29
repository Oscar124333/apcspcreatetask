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

    int userInput = 0;

    Card **playerDeck = deck_construct();
    if (playerDeck == NULL) {return -1;}


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
    
    Card *hand = hand_generate(playerDeck, 5);

    for (int i = 0; i < 5; i++)
    {
        printf("Suit: %s, Rank: %s, Value: %d\n", hand[i].suit, hand[i].rank_string, hand[i].value_base);
    }

    free(hand);
    return 0;
}
