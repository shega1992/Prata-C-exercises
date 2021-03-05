#include <stdio.h>
#define SIZE 40

char * s_gets(char * st, int n);
unsigned int custom_strlen(const char *st);

int main(void)
{
    char string[SIZE];
    unsigned int length;

    fputs("Please enter your string: ", stdout);

    length = custom_strlen(s_gets(string, SIZE));

    printf("String length: %u", length);

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

unsigned int custom_strlen(const char *st)
{
    unsigned int counter = 0;

    while(st != NULL && *st++ != '\0')
        counter += 1;

    return counter;
}
