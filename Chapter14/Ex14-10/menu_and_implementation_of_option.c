#include <stdio.h>
#include <ctype.h>
#include "header.h"

int show_menu(void)
{
    int answer;

    fputs("Please select the option:\n", stdout);
    printf("***********************************\n"
           "1.Print original string\n"
           "2.Print lowercase string\n"
           "3.Print uppercase string\n"
           "***********************************\n");
    scanf("%d", &answer);

    while(answer < 1 || answer > 3)
    {
        printf("You've selected incorrect option\n"
               "Please select the option from 1 to 4\n");
        scanf("%d", &answer);
    }

    return answer;
}

void OrigString(char *str)
{
    // no changes;
}

void ToLower(char *str)
{
    while(*str != '\0')
    {
        *str = tolower(*str);
        str++;
    }
}

void ToUpper(char *str)
{
   while(*str != '\0')
    {
        *str = toupper(*str);
        str++;
    }
}

void show(void (*pf)(char *), char *string)
{
    (*pf)(string);
    puts(string);
}

void eatline(void)
{
    while(getchar() != '\n')
        continue;
}
