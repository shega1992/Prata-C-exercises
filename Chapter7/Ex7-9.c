#include <stdio.h>
#include<stdbool.h>

bool Prime_Number(unsigned int number_for_checking);

int main(void)
{
    unsigned int positive_number;
    int i;

    printf("Please enter a positive integer: ");
    scanf("%u", &positive_number);

    for(printf("Prime numbers: "), i = 2 ; i <= positive_number; i++)
    {
       if(Prime_Number(i))
            printf("%d ", i);
    }

    return 0;
}

bool Prime_Number(unsigned int number_for_checking)
{
    unsigned int divisor;
    bool isPrime;
   for(divisor = 2, isPrime = true ; divisor * divisor <= number_for_checking; divisor++)
   {
       if(number_for_checking % divisor == 0)
            isPrime = false;
   }
   return isPrime;
}
