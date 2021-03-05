#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convert_to_decimal(char *pbin);

int main(void)
{
    char *pbin = "01001001";

    printf("Your number: %d", convert_to_decimal(pbin));
    return 0;
}

int convert_to_decimal(char *pbin)
{
    int i;
    int exponent = 1;
    int number = 0;

    for(i = strlen(pbin) - 1; i >= 0; i--)
    {
        if(pbin[i] == '1')
            number += 1 * exponent;
        exponent *= 2;
    }

    return number;
}
