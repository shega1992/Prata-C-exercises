#include <stdio.h>
#define MIN_PER_HOUR 60

int main(void)
{
    int minutes;

    printf("Please enter the number of minutes: ");
    scanf("%d", &minutes);

    while(minutes > 0)
    {
        printf("We have %d hour(s) and %d minute(s) in %d minute(s)\n",
               minutes/MIN_PER_HOUR, minutes%MIN_PER_HOUR, minutes);

        printf("Enter next value (<=0 to quit): ");
        scanf("%d", &minutes);
    }
    printf("Done!\n");

    return 0;
}
