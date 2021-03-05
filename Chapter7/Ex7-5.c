#include <stdio.h>

int main(void)
{
    unsigned int substitution = 0;
    char character;

    printf("Please enter a string (character # finishes the string): ");

    while((character = getchar()) != '#')
    {
        switch(character)
        {
            case '.':
                putchar('!');
                substitution++;
                break;
            case '!':
                printf("!!");
                substitution++;
                break;
            default:
                putchar(character);
                break;
        }
    }
    printf("\nNumber of substitution: %u", substitution);

    return 0;
}
