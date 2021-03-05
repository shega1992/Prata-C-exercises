#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

void fill_array(double arr[], int n);
void print_array(const double arr[],int n);
double diff(const double arr[], int n);

int main(void)
{
    double arr[SIZE];
    fill_array(arr, SIZE);
    print_array(arr, SIZE);
    putchar('\n');
    printf("The difference between the largest and smallest elements of an array: %.2f" ,
           diff(arr,SIZE));

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

double diff(const double arr[], int n)
{
    double min_value, max_value;
    min_value = max_value = arr[0];

    for(int i = 1; i < n; i++)
        {
            if(min_value > arr[i])
                min_value = arr[i];

            if(max_value < arr[i])
                max_value = arr[i];

        }

    return max_value - min_value;
}
