#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int character;
    unsigned int counter_for_uppercase;
    unsigned int counter_for_lowercase;
    unsigned int counter_for_other_characters;
    counter_for_uppercase = counter_for_lowercase = counter_for_other_characters = 0;

    printf("Your input: ");

    while((character = getchar()) != EOF)
    {
        if(isupper(character))
            counter_for_uppercase++;
        else if(islower(character))
            counter_for_lowercase++;
        else
            counter_for_other_characters++;
    }

    printf("Number of uppercase letters: %u\n"
           "Number of lowercase letters: %u\n"
           "Number of other characters: %u\n",
           counter_for_uppercase, counter_for_lowercase, counter_for_other_characters);

    return 0;
}
