#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int days_per_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool leap_year(int year);
void day_and_month_are_correct(int * , int *);
int number_of_days(int , int );

int main(void)
{
    int day, month, year;

    fputs("Please enter day, month and year: ", stdout);
    while(scanf("%d %d %d", &day, &month, &year) != 3)
    {
        printf("You've entered nonnumeric value for day, month or year\n"
               "Please repeat the input\n"
               "Please enter day, month and year: ");

        while(getchar() != '\n')
            continue;
    }

    days_per_month[1] += leap_year(year);
    day_and_month_are_correct(&day, &month);

    printf("Total: %d days\n", number_of_days(day, month));

    return 0;
2}

bool leap_year(int year)
{
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return true;
    else
        return false;
}

void day_and_month_are_correct(int *day, int *month)
{
    while(*month < 1 || *month > 12)
    {
        printf("You've entered incorrect value for month\n"
               "Please try again\n"
               "Enter the number of month: ");
        scanf("%d", month);
    }

    while(*day < 1 || *day > days_per_month[*month - 1])
    {
        printf("You've entered incorrect value for days\n"
               "Please try again\n"
               "Enter the number of days: ");
        scanf("%d", day);
    }

}

int number_of_days(int day, int month)
{
    int total = 0;

    for(int i = 1; i < month; i++)
        total += days_per_month[i-1];

    total += day;

    return total;
}
