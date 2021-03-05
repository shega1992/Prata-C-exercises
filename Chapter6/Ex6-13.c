#include <stdio.h>
#define SIZE 8

int main(void)
{
    int array_of_integers[SIZE];
    int i;
    array_of_integers[0] = 1;

    for(i = 1; i < SIZE; i++)
        array_of_integers[i] = array_of_integers[i-1] * 2;

    i = 0;
    do{
       printf("%d ", array_of_integers[i]);
       i++;
    }while(i < SIZE);

    return 0;
}
