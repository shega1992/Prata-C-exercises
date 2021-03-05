#include <stdio.h>

int main()
{
    float dividend = 1.0;
    int number_of_elements;
    int i = 1;
    float sum = 0.0;

    printf("Please enter the number of elements of series( <= 0 for exit): ");

    while (scanf("%d", &number_of_elements) == 1 && number_of_elements > 0)
    {
        while(i <= number_of_elements) // 1.0 + 1.0/2.0 + 1.0/3.0 + 1.0/4.0 +...
        {
            sum += dividend / i;
            i++;
        }

        printf("Sum of the first series: %f\n" , sum);
        sum = 0;
        i = 1;

        while(i <= number_of_elements) // 1.0 - 1.0/2.0 + 1.0/3.0 - 1.0/4.0 +...
        {
            if(i % 2 == 0)
                sum += -dividend / i;
            else
                sum += dividend / i;
            i++;
        }
        printf("Sum of the second series: %f\n", sum);
        sum = 0;
        i = 1;

        printf("Please enter the number of elements of series ( <= 0 for exit): ");
    }
    printf("Done!\n");

    return 0;
}


