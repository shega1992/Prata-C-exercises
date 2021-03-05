#include <stdio.h>
#include <ctype.h>
#include "header.h"

int main(void)
{
    char string[SIZE];
    typedef void (*ARR_OF_FUNC)(char *);
    ARR_OF_FUNC array_of_functions[3] = {OrigString, ToLower, ToUpper};

    fputs("Please enter your string(empty string for exit): ", stdout);
    while(s_gets(string, SIZE)!= 0 && string[0] != '\0')
    {
        show(array_of_functions[show_menu() - 1], string);
        eatline();

        fputs("Please enter the next string(empty string for exit): ", stdout);
    }

    return 0;
}

char * s_gets(char * st, int n)
{
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
