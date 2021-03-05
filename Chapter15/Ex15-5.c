#include <stdio.h>
#include <limits.h>

int number_of_moves_is_correct(int number_of_moves);
void print_binary_string(char *bin_str, unsigned int value);
unsigned int rotate(unsigned int x, int number_of_moves);

int main(void)
{
    unsigned int value;
    int number_of_moves;
    char bin_str[CHAR_BIT * sizeof(int) + 1];

    printf("Please enter your value and number of moves to the left: ");
    scanf("%u %d", &value, &number_of_moves);

    number_of_moves = number_of_moves_is_correct(number_of_moves);

    fputs("Value before rotate: ", stdout);
    print_binary_string(bin_str, value);

    value = rotate(value, number_of_moves);

    fputs("Value after rotate:  ", stdout);
    print_binary_string(bin_str, value);

    return 0;
}

int number_of_moves_is_correct(int number_of_moves)
{
    while(number_of_moves < 0)
    {
        printf("You've entered incorrect value for number_of_moves\n"
               "Please enter positive value or 0: ");
        scanf("%d", &number_of_moves);
    }

    return number_of_moves;
}

void print_binary_string(char *bin_str, unsigned int value)
{
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

unsigned int rotate(unsigned int x, int number_of_moves)
{
    while(number_of_moves > 32)
        number_of_moves -= 32;

    int mask = x >> (32 - number_of_moves);
    x <<= number_of_moves;

    return x | mask;
}
