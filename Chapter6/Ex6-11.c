#include <stdio.h>
#define SIZE 8

int main(void)
{
    int array_of_integers[SIZE];
    int i;

    printf("Please enter 8 integer values: ");

    for(i = 0; i <SIZE; i++)
        scanf("%d", &array_of_integers[i]);

    for(printf("Your array of integers: "), i = 0; i < SIZE; i++)
        printf("%d ", array_of_integers[i]);

    for(printf("\nYour array of integers in reverse order: "),
        i = SIZE -1; i>=0; i-- )
        printf("%d ", array_of_integers[i]);

    return 0;
}
