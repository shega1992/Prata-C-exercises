#include <stdio.h>
#define SIZE 26

int main(void)
{
    int i;
    char lowercase_letters[SIZE];
    char letter = 'a';

    for( i = 0; i < SIZE ; i++ )
        lowercase_letters[i] = letter++;

    for(i = 0; i < SIZE; i++)
        printf("%c ", lowercase_letters[i]);

    return 0;
}
