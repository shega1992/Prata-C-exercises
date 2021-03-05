#include <stdio.h>

int main(void)
{
    const unsigned short DAYS_PER_WEEK = 7;
    int days;

    printf("Please enter number of days (<=0 to quit): ");
    scanf("%d", &days);

    while(days > 0)
    {
        printf("%d are %d week(s), %d day(s)\n",
               days, days/DAYS_PER_WEEK, days%DAYS_PER_WEEK);

        printf("Enter next value (<=0 to quit): ");
        scanf("%d", &days);
    }
    printf("Done!\n");

    return 0;

}
