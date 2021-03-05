#include <stdio.h>

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

int number_of_days(int number_of_month);
int input(void);

int main(void)
{
    printf("Total: %d days\n", number_of_days(input()));

    return 0;
}

int number_of_days(int number_of_month)
{
    int total = 0;

    for(int i = 0; i < number_of_month; i++)
        total += arr_of_months[i].days;

    return total;

}

int input(void)
{
    int number_of_month;

    fputs("Enter the number of month: ", stdout);
    while(scanf("%d", &number_of_month) != 1 || number_of_month < 1 || number_of_month > 12)
    {
        printf("You've entered incorrect value for month\n"
               "Please try again\n"
               "Enter the number of month: ");

        while(getchar() != '\n')
            continue;
    }

    return number_of_month;
}
