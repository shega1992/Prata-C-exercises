#include <stdio.h>

int main(void)
{
    float prize = 1000000;
    unsigned short int years;

    for(years = 1; (prize += prize * 0.08 - 100000) > 0; years++)
        printf("Amount of money in %hu years: %f \n", years, prize);

    printf("The money will run out in %hu years", years);


    return 0;
}
