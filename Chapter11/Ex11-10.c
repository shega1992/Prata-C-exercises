#include <stdio.h>
#include <string.h>
#define SIZE 40

char * s_gets(char * st, int n);
char *remove_all_spaces(char *st);

int main(void)
{
    char string[SIZE];

    while(s_gets(string, SIZE) && *string != '\0')
        printf("Your string after removing all spaces: %s\n", remove_all_spaces(string));

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



char *remove_all_spaces(char *st)
{
    char temp;
    char *address_of_space;
    char *address_of_next_char_after_space;
    char *ret_val = st;

    while(strchr(st, ' '))
    {
        if(*st == ' ')
        {
            address_of_space = st;
            address_of_next_char_after_space = st+1;
            do{
               temp = *address_of_space;
               *address_of_space = *address_of_next_char_after_space;
               *address_of_next_char_after_space = temp;

               address_of_space++;
               address_of_next_char_after_space++;

            }while(*address_of_next_char_after_space != '\0');

            *address_of_space = *address_of_next_char_after_space; // *address_of_space gets '\0'

        }

        st++;
    }

    return ret_val;
}
