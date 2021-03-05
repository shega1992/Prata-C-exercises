#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

void get_list(int *start, int *end);
void selection_sort(int list[], int n);
void print_list(int list[], int n);

int main(void)
{
    int list[SIZE];

    get_list(list, list + SIZE);

    fputs("Your array:", stdout);
    print_list(list, SIZE);

    selection_sort(list, SIZE);

    fputs("Your array after sorting: ", stdout);
    print_list(list, SIZE);

    return 0;
}

void get_list(int *start, int *end)
{
    srand(time(0));

    while(start < end)
    {
        *start++ = rand() % 10 + 1;
    }
}

void selection_sort(int list[], int n)
{
    int i,j,temp;

    for(i = 0; i < n-1; i++)
        for(j = i + 1; j < n; j++)
        {
            if(list[j] > list[i])
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
}

void print_list(int list[], int n)
{
    for(int i = 0; i < SIZE; i++)
    {
        if(i % 25 == 0)
            putchar('\n');

        printf("%2d ", list[i]);
    }

    putchar('\n');

}
