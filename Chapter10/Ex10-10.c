#include <stdio.h>
#define SIZE 4

void sum_of_elements(int source1[], int source2[], int target[], int n);
void print_arr(const int arr[], int n);

int main(void)
{
    int source1[SIZE] = {2, 4, 8, 5};
    int source2[SIZE] = {1, 0, 4, 8};
    int target[SIZE];

    sum_of_elements(source1, source2, target, SIZE);

    printf("source1:");
    print_arr(source1, SIZE);

    printf("source2:");
    print_arr(source2, SIZE);

    printf("target: ");
    print_arr(target, SIZE);

    return 0;
}

void sum_of_elements(int source1[], int source2[], int target[], int n)
{
    int i;

    for(i = 0; i < n; i++)
         target[i] = source1[i] + source2[i];

}

void print_arr(const int arr[], int n)
{
    int i;

    for(i = 0; i < n; i++)
        printf("%3d ", arr[i]);
    putchar('\n');

}
