#include <stdio.h>

int main(void)
{
    const int ROW = 6;
    int i,j;
    char letter = 'A';

    for(i = 0; i < ROW; i++)
    {
        for(j = 0; j < i+1; j++)
        {
            printf("%c", letter);
            letter++;
        }
        printf("\n");
    }
    return 0;
}
