#include <stdio.h>

unsigned int on_bits(unsigned int number);

int main(void)
{
    unsigned int number;

    printf("Please enter your number(non-numeric character for exit): ");
    while(scanf("%d", &number))
    {
        printf("number of \"on\" bits: %d\n", on_bits(number));
        printf("Please enter next number(non-numeric character for exit): ");
    }

    return 0;
}

unsigned on_bits(unsigned int number)
{
   int count = 0;

   while(number != 0)
   {
      count += number % 2;
      number = number / 2;
   }

   return count;
}



