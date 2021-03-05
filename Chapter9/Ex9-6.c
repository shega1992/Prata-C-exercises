#include <stdio.h>

double input_is_good(void);
void sort(double *x, double *y, double *z);
void swap(double *, double *);

int main(void)
{
    double x,y,z;


        printf("Enter the value x: ");
        x = input_is_good();
        printf("Enter the value y: ");
        y = input_is_good();
        printf("Enter the value z: ");
        z = input_is_good();

        sort(&x, &y, &z);

        printf("x = %f\n"
               "y = %f\n"
               "z = %f\n",
               x,y,z);

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

void sort(double *x, double *y, double *z)
{
    if(*x > *y)
        swap(x,y);

    if(*x > *z)
        swap(x,z);

    if(*y > *z)
        swap(y,z);

}

void swap(double *number1, double *number2)
{
    double temp;

    temp = *number1;
    *number1 = *number2;
    *number2 = temp;
}
