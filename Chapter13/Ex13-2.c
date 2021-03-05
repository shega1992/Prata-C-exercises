#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int ch;
    FILE *in, *out;

    if(argc != 3)
    {
        printf("Usage: %s filename filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if((in = fopen(argv[1], "rb")) == NULL)
    {
        printf("Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    if((out = fopen(argv[2], "wb")) == NULL)
    {
        printf("Can't open or create %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while((ch = getc(in)) != EOF)
    {
        putc(ch, out);
    }

    if(fclose(in) != 0 || fclose(out) !=0)
        printf("Error in closing files\n");

    return 0;
}
