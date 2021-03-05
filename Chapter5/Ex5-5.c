#include <stdio.h>

int main(void)
{
    int count, days, sum;

    count = 0;
    sum = 0;

    printf("Please enter the number of days: ");
    scanf("%d", &days);

    while(count++ < days)
        sum += count;
    printf("sum = $%d\n", sum);

    return 0;
}
