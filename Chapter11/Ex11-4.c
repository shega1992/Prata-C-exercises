#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 40

char * s_gets(char * st, int n);
char *read_the_characters(char *st1, unsigned int n);

int main(void)
{
    unsigned int max_number_of_char_for_reading;
    char string[SIZE];

    while(s_gets(string, SIZE))
    {
        fputs("Please enter maximal number of characters for reading: ", stdout);
        scanf("%u", &max_number_of_char_for_reading);

        printf("Program has read next characters: %s\n", read_the_characters(string, max_number_of_char_for_reading));

        while(getchar() != '\n')
            continue;
    }


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

char *read_the_characters(char *st1, unsigned int n)
{

    while(ispunct(*st1) || isspace(*st1)) // handle the input if the first character is not a letter
        st1++;

    unsigned int i;
    char *st2 = st1;

    if(n > strlen(st2))
        return st2;
    else
    {
        for(i = 0; i < n; i++)
            ;
        st2[i] = '\0';

        return st2;
    }


}
