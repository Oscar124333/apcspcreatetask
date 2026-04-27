#include "dealer.h"
#include "constants.h"

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

void hand_generate(void/*Card **deck, int handSize*/)
{

    for (int i = 0; i < 5; i++)
    {
        int rand_num = basic_RNG(nano_seed(), 0, SIZE_SUIT);
        printf("%d\n", rand_num);
    }
}