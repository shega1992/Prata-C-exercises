#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

int main(int argc, char *argv[])
{
    FILE *fp;
    char string[SIZE];

    if(argc != 3)
    {
        printf("Usage: %s string filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if((fp = fopen(argv[2], "rb")) == NULL)
    {
        printf("Can't open %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    printf("The string \"%s\" is contained in next file strings:\n", argv[1]);

    while(fgets(string, SIZE, fp))
    {
        if(strstr(string, argv[1]))
            fputs(string, stdout);
    }

    return 0;
}
