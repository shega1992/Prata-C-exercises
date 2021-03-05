#include <stdio.h>

double input_is_good(void);
double larger_of(double , double);

int main(void)
{
    double x,y;

        printf("Enter the first floating-point value: ");
        x = input_is_good();
        printf("Enter the second floating-point value: ");
        y = input_is_good();

        x = y = larger_of(x,y);

        printf("x = %f and y = %f\n", x,y);

    return 0;
}


double input_is_good(void)
{
   double input;
   char ch;

   while(scanf("%lf", &input) != 1)
   {
        while((ch = getchar()) != '\n')
            putchar(ch);
       printf(" is not an floating - point.\nPlease enter an ");
       printf("floating - point value, such as 25.5, -1.78E2, or 3.00: ");
   }

   return input;

}

double larger_of(double x, double y)
{
    return (x > y)? x : y;
}
