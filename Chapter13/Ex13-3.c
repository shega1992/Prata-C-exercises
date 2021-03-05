#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 20

int main(void)
{
    int ch;
    FILE *in, *out;
    char name_in[SIZE];
    char name_out[SIZE];

    printf("Please enter the name of source file without extension: ");
    scanf("%15s", name_in);
    printf("Please enter the name of output file without extension: ");
    scanf("%15s", name_out);

    strcat(name_in, ".txt");
    strcat(name_out, ".txt");


    if((in = fopen(name_in, "r")) == NULL)
    {
        printf("Can't open %s\n", name_in);
        exit(EXIT_FAILURE);
    }

    if((out = fopen(name_out, "w")) == NULL)
    {
        printf("Can't open or create %s\n", name_out);
        exit(EXIT_FAILURE);
    }

    while((ch = getc(in)) != EOF)
    {
        putc(toupper(ch), out);
    }

    if(fclose(in) != 0 || fclose(out) !=0)
        printf("Error in closing files\n");

    return 0;
}
