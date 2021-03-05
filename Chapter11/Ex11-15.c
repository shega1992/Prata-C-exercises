#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define SIZE 40

char * s_gets(char * st, int n);
bool prepare_atoi(char *st);

int main(void)
{
    char string[SIZE];

    while(s_gets(string, SIZE))
    {
        printf("Return value: %u\n", prepare_atoi(string));
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

bool prepare_atoi(char *st)
{
    while(*st != '\0')
    {
        if(!isdigit(*st))
            return false;

        st++;
    }

    return true;
}
