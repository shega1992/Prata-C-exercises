#include <stdio.h>

int main(void)
{
    unsigned int number_of_occurrences = 0;
    char current_character, preceding_character;

    printf("Please enter a string(character # finishes input string): ");

    while((current_character = getchar()) != '#')
    {
        if(preceding_character == 'e' && current_character == 'i')
            number_of_occurrences++;
        preceding_character = current_character;
    }
    printf("Number of occurrences of sequence \"ei\": %u", number_of_occurrences);

    return 0;
}
