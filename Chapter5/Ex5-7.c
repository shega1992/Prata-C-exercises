#include <stdio.h>

void cube(double my_number);

int main(void)
{
    double my_number;

    printf("Please enter your floating point number: ");
    scanf("%lf", &my_number);

    cube(my_number);

    return 0;
}

void cube(double my_number)
{
    printf("Cube of the number %f: ",
           my_number * my_number * my_number);
}
