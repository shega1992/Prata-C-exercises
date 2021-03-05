#include <stdio.h>

int main(void)
{
    const int ROW = 6;
    int i,j;
    char letter;

    for(i = 0; i < ROW; i++)
    {
        for(j = 0, letter ='F'; j< i+1; j++, letter--)
            printf("%c", letter);
        printf("\n");
    }
    return 0;
}
