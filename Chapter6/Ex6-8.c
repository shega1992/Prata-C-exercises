#include <stdio.h>

int main()
{
    float x,y;

    printf("Please enter two floating-point numbers (nonnumeric value(s) for exit): ");

    while(scanf("%f %f", &x, &y) == 2)
    {
        printf("Result: %f\n", (x-y)/(x*y));

        printf("Please enter next two floating-point numbers (nonnumeric value(s) for exit): ");
    }


    printf("Done!\n");

    return 0;
}
