#include <stdio.h>

unsigned long Fibonacci(unsigned long n);

int main(void)
{
    unsigned long n;

    printf("Please enter your Fibonacci number(q for exit): ");

    while(scanf("%lu", &n) == 1)
    {
        printf("Answer for your Fibonacci number: %lu", Fibonacci(n));
        putchar('\n');

         printf("Please enter next Fibonacci number(q for exit): ");
    }
    return 0;
}

unsigned long Fibonacci(unsigned long n)
{
    unsigned int current_number = 2;
    unsigned int previous_number = 1;
    unsigned temp;


    if(n > 2)
    {
        for(int i = 3; i < n; i++){
            temp = current_number;
            current_number += previous_number;
            previous_number = temp;
             }

        return current_number;
    }
    else
    {
       if(n == 0)
            return 0;
       else
            return 1;
    }



}


