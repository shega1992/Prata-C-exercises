#include <stdio.h>

int main(void)
{
    unsigned int number_of_characters = 0;
    int character;

    printf("Your input: ");

    while((character = getchar()) != EOF)
    {
        putchar(character);
        number_of_characters++;
    }

    printf("Number of characters: %u\n", number_of_characters);

    return 0;
}
