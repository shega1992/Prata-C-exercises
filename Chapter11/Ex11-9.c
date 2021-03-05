#include <stdio.h>
#include <string.h>
#define NUMBER_OF_STRINGS 5
#define NUMBER_OF_CHARACTERS 40

char * s_gets(char * st, int n);
int string_is_correct(int i);
void reverse_string(char string[]);
void print_strings(char strings[][NUMBER_OF_CHARACTERS], int rows);

int main(void)
{
    int i;
    char strings[NUMBER_OF_STRINGS][NUMBER_OF_CHARACTERS];

    for(i = 0; i < NUMBER_OF_STRINGS; i++)
    {
        printf("Enter %d string: ", i);
        s_gets(strings[i], NUMBER_OF_CHARACTERS);
    }

    puts("\nYour strings: ");
    print_strings(strings, NUMBER_OF_STRINGS);

    while(printf("Choose the string for reverse(q for exit): ") && scanf("%d", &i))
    {
        i = string_is_correct(i);

        reverse_string(strings[i]);

        printf("Your strings after reverse:\n");
        print_strings(strings, NUMBER_OF_STRINGS);
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

int string_is_correct(int i)
{
    while(i < 0 || i > NUMBER_OF_STRINGS - 1)
    {
        printf("You have entered incorrect string\n"
               "Please select the string from 0 to %d(including %d): ",
               NUMBER_OF_STRINGS - 1, NUMBER_OF_STRINGS -1);
        scanf("%d", &i);
    }

    return i;
}


void reverse_string(char string[])
{
    int i,j;
    char temp;

    for(i = 0, j = strlen(string) - 1; i < j; i++, j--)
    {
        temp = string[i];
        string[i] = string[j];
        string[j] = temp;
    }
}


void print_strings(char strings[][NUMBER_OF_CHARACTERS], int rows)
{
    int i;

    for(i = 0; i < rows; i++)
        printf("%s\n", strings[i]);

}
