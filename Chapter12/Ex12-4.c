#include <stdio.h>

unsigned int my_function(void);

int main(void)
{
    unsigned int ret_val;

    for(int i = 1; i <= 5; i++)
        ret_val = my_function();

    printf("Number of function\'s calls: %u\n", ret_val);

    return 0;
}

unsigned int my_function(void)
{
    static unsigned int number_of_calls;

    return (++number_of_calls);
}
