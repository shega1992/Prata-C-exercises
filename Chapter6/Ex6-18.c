#include <stdio.h>

int main(void)
{
    int friends = 5;
    int week_and_friends_dropped_out;

    for(week_and_friends_dropped_out = 1; friends < 150; week_and_friends_dropped_out++)
    {
        friends = (friends - week_and_friends_dropped_out) * 2;
        printf("%d friends after %d week\n", friends, week_and_friends_dropped_out);
    }

    printf("The count exceeds Dunbar\'s number\n");

    return 0;
}
