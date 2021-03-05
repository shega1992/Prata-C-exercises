#include <stdio.h>

int main(void)
{
    unsigned int number_of_newline_characters, number_of_spaces, number_of_all_other_characters;
    number_of_newline_characters = number_of_spaces = number_of_all_other_characters = 0;
    char character;

    printf("Please enter the sequence of characters (character # finishes the sequence): ");

    while((character = getchar()) != '#')
    {
        if(character == '\n')
            number_of_newline_characters++;
        else if(character == ' ')
            number_of_spaces++;
        else
            number_of_all_other_characters++;
    }
    printf("Number of spaces: %u\n"
           "Number of newline characters: %u\n"
           "Number of all other characters: %u\n",
           number_of_spaces, number_of_newline_characters, number_of_all_other_characters);

    return 0;
}
