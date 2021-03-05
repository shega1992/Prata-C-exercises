#include <stdio.h>
#define SIZE 10

int max_value(const int arr[], int n);

int main(void)
{
    int arr[SIZE] = {10,25,50, -3,8,9,1,45,19,20};

    printf("Maximum value in array: %d\n", max_value(arr, SIZE));

    return 0;
}

int max_value(const int arr[], int n)
{
    int max = arr[0];

    for(int i = 1; i < n; i++)
        if(arr[i] > max)
            max = arr[i];

    return max;
}
