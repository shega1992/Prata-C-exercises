#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

int number_generator(void);
void counter(int number_count[], int number);
void print_result(int *start, int *end);

int main(void)
{
    static int number_count[SIZE];
    srand(time(NULL));

    for(int i = 0; i < 1000; i++)
        counter(number_count, number_generator());

    print_result(number_count, number_count + SIZE);


    return 0;
}

int number_generator(void)
{
    int number = rand() % 10 + 1;

    return number;

}

void counter(int number_count[], int number)
{
    number_count[number - 1] += 1;
}

void print_result(int *start, int *end)
{
    int number_of = 1;

    while(start < end)
        printf("number of %d: %d\n", number_of++, *start++);
}
