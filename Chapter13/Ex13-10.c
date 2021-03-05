#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20


int main(void)
{
    int ch;
    long file_position;
    FILE *fp;
    char name[SIZE];

    fputs("Please enter the file name without extension: ", stdout);
    scanf("%15s", name);

    strcat(name, ".txt");

    if((fp = fopen(name, "r")) == NULL)
    {
        printf("Can't open %s\n", name);
        exit(EXIT_FAILURE);
    }

    printf("Please enter a file position: ");

    while(scanf("%ld", &file_position) && file_position >= 0)
    {
        fseek(fp, file_position, SEEK_SET);

        while((ch = getc(fp)) != EOF)
        {
            if(ch == '\n')
                break;
            else
                putchar(ch);
        }

        printf("\nPlease enter a new file position: ");
    }


    return 0;
}
