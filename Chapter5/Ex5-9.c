#include <stdio.h>

void Temperatures(double F);

int main(void)
{
    double F;
    _Bool rv; // return value

    printf("Please enter a Fahrenheit temperature: ");
    rv = scanf("%lf", &F);
    while(rv == 1)
    {
        Temperatures(F);

        printf("Enter the next Fahrenheit temperature: ");
        rv = scanf("%lf", &F);
    }

    printf("Done!\n");

    return 0;
}

void Temperatures(double F)
{
    // constants for formulas
    const double CELCIUS_5_9 = 5.0/9.0;
    const double CELCIUS_32 = 32.0;
    const double KELVIN_273 = 273.16;

    double C = CELCIUS_5_9 * (F - CELCIUS_32);
    double K = C + KELVIN_273;

    if(K < 0.0)
        K = 0.0;

    printf("Fahrenheit: %.2f F, Celsius: %.2f C, Kelvin: %.2f K\n", F,C,K);
}
