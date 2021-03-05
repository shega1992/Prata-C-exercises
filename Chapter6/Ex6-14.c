#include <stdio.h>
#define SIZE 8

int main(void)
{
    double array_1[SIZE], array_2[SIZE];
    int i;

    printf("Please enter 8 elements for array_1: ");

    for(i = 0; i < SIZE; i++)
        scanf("%lf", &array_1[i]);

    array_2[0] = array_1[0];

    for(i = 1; i < SIZE; i++)
       array_2[i] = array_2[i-1] + array_1[i];


    for(printf("First array:\n"), i = 0; i < SIZE; i++)
        printf("%10f ", array_1[i]);

    for(printf("\nSecond array:\n"), i = 0; i < SIZE; i++)
        printf("%10f ", array_2[i]);


    return 0;
}
