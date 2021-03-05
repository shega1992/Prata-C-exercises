#include <stdio.h>
#define STOP 0

int main(void)
{
    int number;
    float sum_for_even_numbers, sum_for_odd_numbers;
    sum_for_even_numbers = sum_for_odd_numbers = 0;
    int amount_of_even_numbers, amount_of_odd_numbers; // counters
    amount_of_even_numbers = amount_of_odd_numbers = 0;

    printf("Please enter the sequence of numbers (number 0 finishes the sequence): ");

    while(scanf("%d", &number) == 1 && number != STOP)
    {
        if(number % 2 == 0)
        {
            sum_for_even_numbers += number;
            amount_of_even_numbers++;
        }
        else
        {
            sum_for_odd_numbers += number;
            amount_of_odd_numbers++;
        }
    }
    printf("Total number of even integers: %d, average value of the even integers: %f\n\
Total number of odd integers: %d, average value of the odd integers: %f\n",
           amount_of_even_numbers, sum_for_even_numbers / amount_of_even_numbers,
           amount_of_odd_numbers, sum_for_odd_numbers / amount_of_odd_numbers);
    return 0;
}


