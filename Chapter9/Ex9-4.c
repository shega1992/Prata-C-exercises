#include <stdio.h>

double input_is_good(void);
double harmonic_mean(double , double);


int main(void)
{
    double x,y;

    printf("Please enter the first floating-point number: ");
    x = input_is_good();
    printf("Please enter the second floating-point number: ");
    y = input_is_good();

    printf("Harmonic mean: %.2f\n", harmonic_mean(x,y));


    return 0;
}

double input_is_good(void)
{
    double input;
    char ch;

    while(scanf("%lf", &input) != 1)
    {
        while ((ch = getchar()) != '\n')
            putchar(ch); // dispose of bad input
        printf(" is not an floating - point.\nPlease enter an ");
        printf("floating - point value, such as 25.5, -1.78E2, or 3.0: ");
    }

    return input;
}

double harmonic_mean(double x, double y)
{
    return 2 / (1/x + 1/y);
}
