#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

void results(int sets, int sides, int dice)
{
    int i;

    for(i = 0; i < sets; i++)
        printf("%d ", sum_of_points_per_one_throw(sides, dice));
}

int sum_of_points_per_one_throw(int sides, int dice)
{
    int i;
    int total = 0;

    for(i = 0; i < dice; i++)
        total += generator_for_one_dice(sides);

    return total;
}

int generator_for_one_dice(int sides)
{
    int points_per_one_dice = rand() % sides + 1;

    return points_per_one_dice;
}
