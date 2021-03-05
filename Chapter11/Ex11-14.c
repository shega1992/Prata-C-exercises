#include <stdio.h>
#include <stdlib.h>

double power(double n, int p);

int main(int argc, char *argv[])
{
    printf("%f to the power of %d is %f\n",
               atof(argv[1]), atoi(argv[2]), power(atof(argv[1]), atoi(argv[2])));

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
