#include <stdio.h>
#include <ctype.h>

int main()
{
    float number_of_letters_in_all_words = 0;
    int number_of_words = 0;
    int character;

    printf("Your input: ");

    while((character = getchar()) != EOF)
    {
        if(isspace(character) || ispunct(character))
            number_of_words++;
        else
            number_of_letters_in_all_words++;
    }
    printf("Average number of letters per word: %f",
           number_of_letters_in_all_words/ number_of_words);
    return 0;
}
