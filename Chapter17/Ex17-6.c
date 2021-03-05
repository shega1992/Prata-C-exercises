#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define SIZE 10

void fill_array(int arr[], int n);
void selection_sort(int arr[], int n);
bool binary_search(int arr[], int n, int number_for_searching);
void print_array(int arr[], int n);

int main(void)
{
    int arr[SIZE];
    int number_for_searching;

    srand(time(NULL));

    fill_array(arr, SIZE);

    fputs("Original array: ", stdout);
    print_array(arr, SIZE);

    selection_sort(arr, SIZE);
    fputs("Array after sorting: ", stdout);
    print_array(arr, SIZE);

    fputs("Please enter a number for searching: ", stdout);
    scanf("%d", &number_for_searching);

    printf("Returned value: %d", binary_search(arr, SIZE, number_for_searching));

    return 0;
}

void fill_array(int arr[], int n)
{
    int i;

    for(i = 0; i < SIZE; i++)
        arr[i] = rand() % 100 + 1;
}

void selection_sort(int arr[], int n)
{
    int i,j, temp;

    for(i = n -1; i > 0; i--)
        for(j = i - 1; j >= 0; j--)
        {
            if(arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
}

bool binary_search(int arr[], int n, int number_for_searching)
{
    int low = 0;
    int high = n - 1;
    int mid;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(arr[mid] == number_for_searching)
            return true;
        else if(arr[mid] < number_for_searching)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return false;
}


void print_array(int arr[], int n)
{
    int i;

    for(i = 0; i < SIZE; i++)
        printf("%d ", arr[i]);
    putchar('\n');
}

