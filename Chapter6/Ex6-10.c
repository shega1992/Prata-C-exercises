#include <stdio.h>

int sum_of_integer_squares(int lower_limit, int upper_limit);

int main(void)
{
    int lower_limit, upper_limit;

    printf("Please enter lower and upper integer limits(lower_limit >= upper_limit for exit): ");
    scanf("%d %d", &lower_limit, &upper_limit);

    while(lower_limit < upper_limit)
    {
        printf("The sum of the squares from %d to %d is %d\n",
               lower_limit* lower_limit, upper_limit * upper_limit,
               sum_of_integer_squares(lower_limit, upper_limit));

        printf("Enter next set of limits(lower_limit >= upper_limit for exit): ");
        scanf("%d %d", &lower_limit, &upper_limit);
    }

    printf("Done!\n");

    return 0;
}

int sum_of_integer_squares(int lower_limit, int upper_limit)
{
    int sum = 0;

    for(; lower_limit <= upper_limit; lower_limit++)
        sum += lower_limit * lower_limit;

    return sum;
}
