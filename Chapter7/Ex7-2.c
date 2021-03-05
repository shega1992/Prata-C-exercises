#include <stdio.h>

int main(void)
{
    unsigned int counter;
    char character;

    printf("Please enter the sequence of characters (character # finishes the sequence): ");

    for( counter = 0; (character = getchar()) != '#'; counter++)
    {
        if(counter % 8 == 0)
            putchar('\n');

         printf("\"%c-%3u\" ", character, character);
    }
    return 0;
}
