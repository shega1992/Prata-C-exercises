#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 81

char * s_gets(char * st, int n);
int count_for_standard_input(char *st, int search_char);

int main(int argc, char *argv[])
{
    int ch,i;
    int search_char = *argv[1];
    FILE *fp;

    if(argc < 2)
    {
        printf("Usage: %s arguments (one or more)\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if(argc == 2)
    {
        char string[SIZE];
        if(s_gets(string, SIZE))
        {
           printf("Number of occurrences of %c in standard input: %d\n",
                   search_char, count_for_standard_input(string,search_char));

           exit(EXIT_SUCCESS);
        }
        else
        {
            puts("You have entered EOF character");
            exit(EXIT_SUCCESS);
        }

    }

    for(i = 2; i < argc; i++)
    {
        if((fp = fopen(argv[i], "r")) == NULL)
        {
            printf("Can't open %s\n", argv[i]);
            continue;
        }
        else
        {
            int count = 0;

            while((ch = getc(fp)) != EOF)
            {
                if(ch == search_char)
                    count++;
            }

            printf("Number of occurrences of %c in %s: %d\n",
                   search_char, argv[i], count);

            if(fclose(fp) != 0)
                fprintf(stderr, "Error in closing file %s\n", argv[i]);
        }
    }

    return 0;
}

char * s_gets(char * st, int n)
{
    printf("You have selected the standard input from keyboard\n"
           "Please enter your string: ");

    char * ret_val;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
         while (*st != '\n' && *st != '\0')
             st++;
         if (*st == '\n')
             *st = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

int count_for_standard_input(char *st, int search_char)
{
    int count = 0;

    while(*st != '\0')
    {
        if(*st == search_char)
            count++;

        st++;
    }

    return count;
}
