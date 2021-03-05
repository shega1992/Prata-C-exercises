#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"


int main(void)
{
    int sets, sides, dice;

    srand(time(NULL));

    printf("Enter the number of sets; enter q or nonpositive number to stop : ");

    while(scanf("%d", &sets) == 1 && sets > 0)
    {
        printf("How many sides and how many dice? ");

        while(scanf("%d %d", &sides, &dice) != 2 || sides <= 0 || dice <= 0)
        {
            printf("You have entered incorrect value for sides or dice\n"
                   "Please try again\n" "How many sides and how many dice? ");

            while(getchar() != '\n')
                continue;
        }


        printf("Here are %d sets of %d %d-sided throws\n", sets, dice, sides);
        results(sets, sides, dice);


        printf("\nEnter the next number of sets; enter q or negative number to stop : ");
    }
    return 0;
}
