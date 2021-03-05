#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 10

void fill_array(double arr[], int n);
void print_array(const double arr[],int n);
void reverse_array(double arr[], int n);

int main(void)
{
    double arr[SIZE];
    fill_array(arr, SIZE);

    printf("Your array:    ");
    print_array(arr, SIZE);
    putchar('\n');

    reverse_array(arr, SIZE);

    printf("Reverse array: ");
    print_array(arr,SIZE);

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
    for(i = 0; i < n; i++)
        printf("%5.2f ", arr[i]);
}

void reverse_array(double arr[], int n)
{
    double temp;
    int i,j;

    for(i = 0, j = n-1; i < j; i++, j--)
    {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}
