#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int ch,i;
    FILE *fp;

    if(argc < 2)
    {
        printf("Usage: %s arguments (one or more)\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for(i = 1; i < argc; i++)
    {
        if((fp = fopen(argv[i], "r")) == NULL)
        {
            printf("Can't open %s\n", argv[i]);
            exit(EXIT_FAILURE);
        }
        else
        {
            while((ch = getc(fp)) != EOF)
                putchar(ch);

            if(fclose(fp) != 0)
                fprintf(stderr, "Error in closing file %s\n", argv[i]);
        }
    }


    return 0;
}
