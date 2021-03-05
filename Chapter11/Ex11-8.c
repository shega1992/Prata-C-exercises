#include <stdio.h>
#include <stdbool.h>
#define SIZE 40

char * s_gets(char * st, int n);
char *string_in(const char *s1, const char *s2); // strstr analog

int main(void)
{
    char s1[SIZE];
    char s2[SIZE];

    while(printf("Please enter the string s1(Ctrl + z for exit): ") && s_gets(s1, SIZE) &&
          printf("Please enter the string s2(Ctrl + z for exit): ") && s_gets(s2, SIZE))
        printf("Function has returned address: %p\n", string_in(s1, s2));


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

char *string_in(const char *s1, const char *s2)
{
    int i;
    char *ret_val;
    char *ptr_s1;
    bool s2_is_not_finished = true;

    while(s2_is_not_finished && *s1 != '\0')
    {
        ptr_s1 = s1;
        ret_val = s1;
        i = 0;

        while((s2_is_not_finished = s2[i] != '\0'))
        {
            if(*ptr_s1++ == s2[i++])
                continue;
            else
            {
                ret_val = NULL;
                break;
            }
        }

        s1++;
    }

    return ret_val;
}
