#include <stdio.h>


int main(void)
{
    float amount_of_water;

    printf("Please enter amount of water,in quarts: ");
    scanf("%f", &amount_of_water);
    /*The mass of a single molecule of water is about 3.0E-23 grams.
    A quart of water is about 950 grams */
    printf("Number of water molecules in your amount is %f", amount_of_water * 950.0 / 3.0E-23);
    return 0;
}
