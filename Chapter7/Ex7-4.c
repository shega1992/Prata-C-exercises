#include <stdio.h>

int main(void)
{
    unsigned int substitution = 0;
    char character;

    printf("Please enter a string (character # finishes the string): ");

    while((character = getchar()) != '#')
    {
        if(character == '.')
        {
            putchar('!');
            substitution++;
        }
        else if(character == '!')
        {
            printf("!!");
            substitution++;
        }
        else
            putchar(character);
    }
    printf("\nNumber of substitution: %u", substitution);

    return 0;
}
