#include <stdio.h>
#include <stdlib.h>

int bit_position_is_correct(int bit_position);
int test(unsigned int value, int bit_position);

int main(void)
{
    unsigned int value;
    int bit_position;

    printf("Please enter your value and bit_position(non-numeric value(s) for exit): ");
    while(scanf("%u %d", &value, &bit_position) == 2)
    {
       bit_position = bit_position_is_correct(bit_position);

       printf("bit in position %d is %d\n", bit_position, test(value, bit_position));
       printf("Please enter next value and bit_position(non-numeric value(s) for exit): ");
    }

    return 0;
}

int bit_position_is_correct(int bit_position)
{
    while(bit_position < 0)
    {
        printf("You've entered incorrect value for bit position\n"
               "Please enter positive value or 0: ");
        scanf("%d", &bit_position);
    }

    return bit_position;
}

int test(unsigned int value, int bit_position)
{
   int i;

     for(i = 0; i < bit_position; i++)
          value = value / 2;

   return value % 2;
}
