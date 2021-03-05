#include <stdio.h>
#include <ctype.h>
#define SIZE 40

char * s_gets(char *st, int n);

int main(void)
{
    char string[SIZE];

    printf("Input will stop after %d characters or after whitespace character\n", SIZE - 1);

    while(s_gets(string, SIZE))
        printf("Result: %s\n", string);

    return 0;
}


char * s_gets(char *st, int n)
{
    fputs("Your string(Ctrl+z for exit): ", stdout);

    char * ret_val;
    ret_val = fgets(st, n, stdin);
    if (ret_val) // i.e., ret_val != NULL
        {
            while (!isspace(*st) && *st != '\0')
                st++;
            if (isspace(*st))
                *st = '\0';
            else // must have words[i] == '\0'
                while ( getchar() != '\n')
                    continue;
        }
    return ret_val;

}



