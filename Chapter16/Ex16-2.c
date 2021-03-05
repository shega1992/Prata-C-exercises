#include <stdio.h>
#define HARMONIC_MEAN(X,Y) (2 / (1/X + 1/Y))

float input_is_correct(float number);

int main(void)
{
    float x,y;

    fputs("Please enter two positive numbers(non-numeric character(s) for exit): ", stdout);
    while(scanf("%f %f", &x, &y) == 2)
    {
        x = input_is_correct(x);
        y = input_is_correct(y);

        printf("Harmonic mean of %f and %f is %f\n", x, y, HARMONIC_MEAN(x,y));

        fputs("Please enter next numbers(non-numeric character(s) for exit): ", stdout);
    }

    return 0;
}

float input_is_correct(float number)
{
    while(number <= 0)
    {
        printf("You've entered zero(s) or negative number(s)\n"
               "Please enter a positive number(s): ");
        scanf("%f", &number);
    }

    return number;
}
