#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 40

char * s_gets(char * st, int n);
void implementation_of_options(char *st, char *option);

int main(int argc, char *argv[])
{
    char string[SIZE];

    while(s_gets(string, SIZE))
    {
        if(argc < 2)
            puts(string);
        else
            implementation_of_options(string, argv[1]);
    }

    return 0;
}

char * s_gets(char * st, int n)
{
    fputs("Your string(Ctrl+z): ", stdout);

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

void implementation_of_options(char *st, char *option)
{
    int i;
    char selection;

   if(*option != '-')
        printf("Command-line argument is not correct\n"
               "It has to start with \'-\' character\n");
   else
   {
       selection = *(option + 1);

       switch(selection)
       {
            case 'p':
                puts(st);
                break;
            case 'u':
                for(i = 0; st[i] != '\0'; i++)
                    st[i] = toupper(st[i]);
                puts(st);
                break;
            case 'l':
                for(i = 0; st[i] != '\0'; i++)
                   st[i] = tolower(st[i]);
                puts(st);
                break;
            default:
                printf("Command-line argument is not correct\n"
               "Please choose one from list: -p -u or -l\n");
                break;

       }
   }

}
