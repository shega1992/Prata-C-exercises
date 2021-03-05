#include <stdio.h>
#include <stdbool.h>

unsigned short int base_is_correct(unsigned short int base);
void to_base_n(unsigned long n, unsigned short int base);

int main(void)
{
    unsigned long number;
    unsigned short int base;

    printf("Please enter your number and base for conversion(q for exit): ");

    while(scanf("%lu %hu", &number, &base) == 2)
    {
        base = base_is_correct(base);
        printf("the base-%hu equivalent of %lu is ", base, number);
        to_base_n(number, base);
        putchar('\n');

        printf("Please enter your number and base for conversion(q for exit): ");
    }

    return 0;
}

unsigned short int base_is_correct(unsigned short int base)
{
    bool base_is_bad = true;

    while(base_is_bad)
    {
        if(base < 2 || base > 9){
                printf("Base for conversion is not correct\n"
                       "Please choose a base from 2 to 9: ");
                scanf("%hu", &base);
        }
        else
            base_is_bad = false;
    }

    return base;
}



void to_base_n(unsigned long n, unsigned short int base)
{
    unsigned int remainder;

    remainder = n % base;

    if(n >= base)
        to_base_n(n / base, base);
    printf("%lu", remainder);

}
