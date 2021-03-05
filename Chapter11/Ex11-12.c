#include <stdio.h>
#include <ctype.h>
#define SIZE 40

char * s_gets(char * st, int n);
void calculations(char *st, int n);

int main(void)
{
    char string[SIZE];

    while(s_gets(string, SIZE))
        calculations(string, SIZE);


    return 0;
}

char * s_gets(char * st, int n)
{
    fputs("Your string(Ctrl+z for exit): ", stdout);

    char * ret_val;
    ret_val = fgets(st, n, stdin);
    if (ret_val) // i.e., ret_val != NULL
        {
            while (*st != '\n' && *st != '\0')
                st++;
            if (*st == '\n')
                *st = '\0';
            else // must have words[i] == '\0'
                while ( getchar() != '\n')
                    continue;
        }
    return ret_val;

}

void calculations(char *st, int n)
{
    unsigned int number_of_words = 0;
    unsigned int number_of_uppercase_letters = 0;
    unsigned int number_of_lowercase_letters = 0;
    unsigned int number_of_punctuation_characters = 0;
    unsigned int number_of_digits = 0;

    while(ispunct(*st) || isspace(*st)) // handle the input if the first character is not a letter
    {
        if(ispunct(*st))
            number_of_punctuation_characters++;

        st++;
    }

    while(*st != '\0')
    {
        if(isalnum(*st))
        {
            if(isupper(*st))
                number_of_uppercase_letters++;
            else if(islower(*st))
                number_of_lowercase_letters++;
            else
                number_of_digits++;
        }
        else if((ispunct(*st) || isspace(*st)) && isalnum(*(st-1)))
        {
            if(ispunct(*st))
            {
                number_of_punctuation_characters++;
                number_of_words++;
            }
            else
               number_of_words++;

        }
        else if(ispunct(*st))
            number_of_punctuation_characters++;


        st++;
    }

    if(isalnum(*(st-1)))
       number_of_words++;

    printf("Number of words: %u\n"
           "Number of uppercase letters: %u\n"
           "Number of lowercase letters: %u\n"
           "Number of punctuation characters: %u\n"
           "Number of digits: %u\n",
           number_of_words,
           number_of_uppercase_letters,
           number_of_lowercase_letters,
           number_of_punctuation_characters,
           number_of_digits);

}
