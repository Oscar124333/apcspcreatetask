#include "dealer.h"
#include "constants.h"
#include "cards.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned int nano_seed(void)
{   // From AI
    struct timespec seed;
    if (clock_gettime(CLOCK_MONOTONIC, &seed) == -1)
    {
        perror("clock_gettime error");
    }
    unsigned int seedOut = (unsigned int)(seed.tv_sec ^ seed.tv_nsec);
    return seedOut;
}

int basic_RNG(unsigned int seed, int rangeStart, int rangeEnd)
{
    int output = 0;
    srand(seed);
    output = (rand() % (rangeEnd - rangeStart)) + rangeStart;
    return output;
}

void hand_generate(Card **deck, int handSize)
{

    for (int i = 0; i < handSize; i++)
    {
        int suit = 0;
        int incCount = 0;
        int randNum = basic_RNG(nano_seed(), 0, SIZE_SUIT);

        Card *chosen = &deck[suit][randNum];
        while (chosen->drawn == true)
        {
            incCount++;
            suit++;
            suit %= NUMBER_SUITS;
            if (incCount >= NUMBER_SUITS)
            {
                randNum++;
                randNum %= SIZE_SUIT;
            }
            chosen = &deck[suit][randNum];
        }
        printf("%s of %s\n", chosen->rank_string, chosen->suit);
        chosen->drawn = true;
    }
}