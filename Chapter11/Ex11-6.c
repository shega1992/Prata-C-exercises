#include <stdio.h>
#include <stdbool.h>
#define SIZE 40

char * s_gets(char * st, int n);
bool is_within(const char *string, int character);


int main(void)
{
   char string[SIZE];
   bool ret_value;

   fputs("Your string(Ctrl + z for exit): ", stdout);

   while(s_gets(string, SIZE))
   {

       fputs("Enter the character for searching: ", stdout);
       (ret_value = is_within(string, getchar()))?
       printf("Return value: %u\n", ret_value) :
           printf("Return value: %u\n", ret_value);

        while(getchar() != '\n')
            continue;

       fputs("Enter next string(Ctrl + z for exit): ", stdout);
   }
    return 0;
}

bool is_within(const char *string, int character)
{

    while(*string != '\0')
    {
        if(*string == character)
            return true;

        string++;
    }

    return false;
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
