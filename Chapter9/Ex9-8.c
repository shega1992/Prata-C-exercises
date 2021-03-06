#include <stdio.h>
#include <stdlib.h>

double power(double n, int p);

int main(void)
{
    double number;
    int exponent;

    printf("Please enter your number and exponent(q for exit): ");

    while(scanf("%lf %d", &number, &exponent))
    {
        printf("%f to the power of %d is %f\n",
               number, exponent, power(number, exponent));

        printf("Please enter next number and exponent(q for exit): ");
    }
    return 0;
}

double power(double n, int p)
{
    double pow = 1.0;
    int i;

    if(n == 0)
    {
        if(p == 0)
        {
            printf("0 to power of 0 is undefined. Function is using 1 as return value\n");
            return pow;
        }
        else
            return 0.0;
    }
    else
    {
       for(i = 1; i <= abs(p); i++)
            pow *= n;

       if(p < 0)
            return 1.0/pow;
       else
            return pow;
    }

}
