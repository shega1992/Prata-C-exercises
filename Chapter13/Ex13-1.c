/* count.c -- using standard I/O */
#include <stdio.h>
#include <stdlib.h> // exit() prototype
#include <string.h>
#define SIZE 20

int main(void)
{
    char name[SIZE];
    int ch; // place to store each character as read
    FILE *fp; // "file pointer"
    unsigned long count = 0;

    printf("Please enter file name without extension: ");
    scanf("%15s", name);

    strcat(name, ".txt");



    if ((fp = fopen(name, "r")) == NULL)
    {
        printf("Can't open %s\n", name);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp)) != EOF)
    {
        putc(ch,stdout); // same as putchar(ch);
        count++;
    }

    fclose(fp);
    printf("File %s has %lu characters\n", name, count);


    return 0;
}
