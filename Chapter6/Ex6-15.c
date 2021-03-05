#include <stdio.h>
#define SIZE 256

int main()
{
    int i = 0;
    char array_of_characters[SIZE];

    printf("Please enter a string: ");

    do{
        scanf("%c", &array_of_characters[i]);
    }while(array_of_characters[i++] != '\n');

    for(i -=1; i>=0; i--)
        printf("%c", array_of_characters[i]);
}
