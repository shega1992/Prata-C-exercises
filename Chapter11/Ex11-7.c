#include <stdio.h>
#define SIZE_SOURCE 50
#define SIZE_TARGET 40

char * s_gets(char * st, int n);
unsigned int input_is_correct(unsigned int n);
char *mystrncpy(char *target, char *source, unsigned int n);

int main(void)
{
    unsigned int n;
    char source[SIZE_SOURCE];
    char targer[SIZE_TARGET];

    while(s_gets(source, SIZE_SOURCE))
    {
        fputs("Enter number of elements to copy: ", stdout);
        scanf("%u", &n);

        n = input_is_correct(n);

        printf("Target string: %s\n", mystrncpy(targer, source, n));

        while(getchar() != '\n')
            continue;

    }

    return 0;
}

char * s_gets(char * st, int n)
{
    fputs("Your source string: ", stdout);

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

unsigned int input_is_correct(unsigned int n)
{
    while(n > SIZE_TARGET - 1)
    {
        printf("Incorrect value of elements for copying\n"
               "Please enter %d or less: ", SIZE_TARGET - 1);
        scanf("%u", &n);
    }
    return n;
}

char *mystrncpy(char *target, char *source, unsigned int n)
{
    int i = 0;

    while(source[i] != '\0' && i < n)
    {
        target[i] = source[i];
        i++;
    }

    while(i < SIZE_TARGET)
        target[i++] = '\0';



    return target;
}
