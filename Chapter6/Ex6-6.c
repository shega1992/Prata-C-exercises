#include <stdio.h>

int square(int lower_limit);
int cube(int lower_limit);

int main(void)
{
    int lower_limit, upper_limit;

    printf("Please enter the lower and upper limits: ");
    scanf("%d %d", &lower_limit, &upper_limit);

    printf("Number    Square    Cube\n");

    for(; lower_limit <= upper_limit; lower_limit++)
    {
       printf("%4d %10d %8d", lower_limit, square(lower_limit), cube(lower_limit));
       printf("\n");
    }

    return 0;
}

int square(int lower_limit)
{
    return lower_limit * lower_limit;
}

int cube(int lower_limit)
{
    return lower_limit * lower_limit * lower_limit;
}

