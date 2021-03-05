#include <stdio.h>
#include <ctype.h>
#define SIZE 40

char * s_gets(char * st, int n);
char *read_the_first_word(char *st);

int main(void)
{
    char string[SIZE];

    while(s_gets(string, SIZE))
        printf("First word from input line: %s\n", read_the_first_word(string));

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

char *read_the_first_word(char *st)
{

    while(ispunct(*st) || isspace(*st)) // handle the input if the first character is not a letter
        st++;

    char *ret_val = st;

    while(isalnum(*st))
        st++;
    *st = '\0';

    return ret_val;
}
