#include <stdio.h>

typedef struct Card
{
    char *value_string;
    char *suit;
    unsigned short const value_const;
    float multiplier;

    int (*value_total)(struct Card*);
} Card;

int value_total(Card* card)
{
    return card->value_const * card->multiplier;
}

int main(void)
{
    Card test = {"King", .suit = "Spades", .value_const = 10, .multiplier = 1.5};

    int x = test.value_total(&test);

    return 0;
}
