#include <stdio.h>

double min(double , double );

int main(void)
{
    double x,y;

    printf("Enter two double-precision floating-point values \
(any non-numeric character for exit): ");

    while(scanf("%lf %lf", &x, &y) == 2)
    {
        printf("The lesser of %f and %f is %f.\n",
               x,y, min(x,y));

        printf("Enter next two double-precision floating-point values \
(any non-numeric character for exit): ");
    }

    printf("The program has been completed\n");

    return 0;
}

double min(double x, double y)
{
    return (x < y)? x : y;
}
