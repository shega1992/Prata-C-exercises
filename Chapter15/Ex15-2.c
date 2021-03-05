#include <stdio.h>
#include <string.h>
#include <limits.h>

int convert_to_decimal(char *pbin);
void bitwise_logical_operators(int x, int y);
void print_results_as_binary_strings(int value);

int main(int argc, char *argv[])
{
    int x,y;
    for(int i = 1; i < argc; i++)
        printf("Argument %d is %s\n", i, argv[i]);
    puts("x is the first argument\ny is the second argument");

    x = convert_to_decimal(argv[1]);
    y = convert_to_decimal(argv[2]);

    bitwise_logical_operators(x,y);

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

void bitwise_logical_operators(int x, int y)
{
    int not_x = ~x;
    int not_y = ~y;
    int x_and_y = x & y;
    int x_or_y = x | y;
    int x_xor_y = x ^ y;

    fputs("not x: ", stdout);
    print_results_as_binary_strings(not_x);

    fputs("not y: ", stdout);
    print_results_as_binary_strings(not_y);

    fputs("x and y: ", stdout);
    print_results_as_binary_strings(x_and_y);

    fputs("x or y: ", stdout);
    print_results_as_binary_strings(x_or_y);

    fputs("x xor y: ", stdout);
    print_results_as_binary_strings(x_xor_y);

}

void print_results_as_binary_strings(int value)
{
    char bin_str[CHAR_BIT * sizeof(int) + 1];
    int i;
    const static int size = CHAR_BIT * sizeof(int);

    for(i = size - 1; i >= 0; i--, value >>= 1)
        bin_str[i] = (01 & value) + '0';
    bin_str[size] = '\0';

    i = 0;

    while(bin_str[i])
    {
        putchar(bin_str[i]);
        if(++i % 4 == 0 && bin_str[i])
            putchar(' ');
    }

    putchar('\n');
}
