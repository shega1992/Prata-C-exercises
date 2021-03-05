#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 20

int main(void)
{
    FILE *in, *out;
    int ch;
    char name[LEN];
    int count = 0;

    printf("Please enter file name without extension: ");
    scanf("%15s", name);

    strcat(name, ".txt");

    if ((in = fopen(name, "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n",
                name);
        exit(EXIT_FAILURE);
    }



    if ((out = fopen("Copy.txt", "w")) == NULL)
    {
        fprintf(stderr,"Can't create output file.\n");
        exit(3);
    }

    while ((ch = getc(in)) != EOF)
        if (count++ % 3 == 0)
            putc(ch, out);

    if (fclose(in) != 0 || fclose(out) != 0)
            fprintf(stderr,"Error in closing files\n");

    return 0;
}
