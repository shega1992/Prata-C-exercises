#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    int ch;
    FILE *first_file, *second_file;
    bool first_file_has_a_char, second_file_has_a_char;
    first_file_has_a_char = second_file_has_a_char = true;

    if(argc != 3)
    {
        printf("Usage: %s filename filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if((first_file = fopen(argv[1], "r")) == NULL)
    {
        printf("Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if((second_file = fopen(argv[2], "r")) == NULL)
    {
        printf("Can't open or create %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while(first_file_has_a_char || second_file_has_a_char)
    {
        while((ch = getc(first_file)) != EOF)
        {
            if(ch == '\n')
                break;
            else
                putchar(ch);
        }

        if(ch == EOF)
            first_file_has_a_char = false;

        while((ch = getc(second_file)) != EOF)
        {
            if(ch == '\n')
                break;
            else
                putchar(ch);
        }

        if(ch == EOF)
            second_file_has_a_char = false;

        putchar('\n');

    }

    if(fclose(first_file) != 0 || fclose(second_file) !=0)
        printf("Error in closing files\n");

    return 0;
}
