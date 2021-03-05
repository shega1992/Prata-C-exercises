#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

void fill_array(double arr[], int n);
void print_array(const double arr[],int n);
unsigned int index_of_max_value (const double arr[], int n);

int main(void)
{
    double arr[SIZE];
    fill_array(arr, SIZE);
    print_array(arr, SIZE);
    putchar('\n');
    printf("Index of the largest value stored in an array: %u" ,
           index_of_max_value(arr,SIZE));

    return 0;
}

void fill_array(double arr[], int n)
{
    srand(time(NULL));
    for(int i = 0; i < n; i++)
        arr[i] = rand() % 100;

}

void print_array(const double arr[], int n)
{
    int i;
    for(printf("Your array: "), i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
}

unsigned int index_of_max_value(const double arr[], int n)
{
    double max_value = arr[0];
    unsigned int index_of_the_largest_value;

    for(int i = 1; i < n; i++)
        if(arr[i] > max_value)
        {
            max_value = arr[i];
            index_of_the_largest_value = i;
        }

    return index_of_the_largest_value;
}
