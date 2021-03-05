#include <stdio.h>
#include <string.h>
#define SIZE 40

char * s_gets(char * st, int n);

int main(void)
{
    char string[SIZE];

    fputs("Please enter your string: ", stdout);

    (s_gets(string, SIZE))? printf("Your string: %s\n", string) : printf("Function has returned NULL pointer\n");

    return 0;

}

char * s_gets(char * st, int n)
{
    char * ret_val;
    ret_val = fgets(st, n, stdin);
    if (ret_val) // i.e., ret_val != NULL
        {
            st = strchr(st, '\n');
            if (st)
                *st = '\0';
            else // must have words[i] == '\0'
                while (getchar() != '\n')
                    continue;
        }
    return ret_val;

}
