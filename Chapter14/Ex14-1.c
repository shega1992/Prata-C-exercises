#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct months{
    char name[10];
    char abbr[4];
    int days;
    int month_number;
};

struct months arr_of_months[12] = {
    {"January", "jan", 31, 1},
    {"February", "feb", 28, 2},
    {"March", "mar", 31, 3},
    {"April", "apr", 30, 4},
    {"May", "may", 31, 5},
    {"June", "jun", 30, 6},
    {"July", "jul", 31, 7},
    {"August", "aug", 31, 8},
    {"September", "sep", 30, 9},
    {"October", "oct", 31, 10},
    {"November", "nov", 30, 11},
    {"December", "dec", 31, 12}
};

int number_of_days(char name_of_month[]);
void enter_the_name_of_month(char name_of_month[]);

int main(void)
{
    char name_of_month[10];

    enter_the_name_of_month(name_of_month);

    printf("Total: %d days\n", number_of_days(name_of_month));

    return 0;
}

int number_of_days(char name_of_month[])
{
    int number_of_month;
    int total = 0;

    for(number_of_month = 1; number_of_month <= 12; number_of_month++)
    {
        if(strcmp(name_of_month, arr_of_months[number_of_month - 1].name) == 0)
            break;
    }

    if(number_of_month > 12)
    {
        puts("Invalid month");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < number_of_month; i++)
        total += arr_of_months[i].days;

    return total;

}

void enter_the_name_of_month(char name_of_month[])
{
    fputs("Enter the name of month: ", stdout);
    scanf("%10s", name_of_month);

    name_of_month[0] = toupper(name_of_month[0]);

    for(int i = 1; *name_of_month != '\0'; name_of_month++)
        name_of_month[i] = tolower(name_of_month[i]);

}
