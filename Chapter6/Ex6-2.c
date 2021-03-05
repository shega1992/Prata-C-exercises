#include <stdio.h>

int main(void)
{

    const int ROW = 5;

    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < i+1; j++)
            printf("$");
        printf("\n");
    }

    return 0;
}
