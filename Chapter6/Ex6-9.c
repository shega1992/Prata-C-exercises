#include <stdio.h>

float calculation(float x, float y);

int main()
{
    float x,y;

    printf("Please enter two floating-point numbers (nonnumeric value(s) for exit): ");

    while(scanf("%f %f", &x, &y) == 2)
    {
        printf("Result: %f\n", calculation(x,y));

        printf("Please enter next two floating-point numbers (nonnumeric value(s) for exit): ");
    }
    printf("Done!\n");

    return 0;
}

float calculation(float x, float y)
{
    return (x-y)/(x*y);
}
