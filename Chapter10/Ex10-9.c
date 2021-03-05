#include <stdio.h>
#define ROWS 3
#define COLS 5

void copy_arr(int rows, int cols, double source[rows][cols]);
void print_arr(int rows, int cols, double arr[rows][cols]);

int main(void)
{
    double source[ROWS][COLS] =
    {
      {1.1, 2.2, 3.3, 4.4, 5.5},
      {6.6, 7.7, 8.8 , 9.9, 10.10},
      {11.11, 12.12, 13.13, 14.14, 15.15}
    };

     copy_arr(ROWS, COLS, source);

    return 0;
}

void copy_arr(int rows, int cols, double source[rows][cols])
{
    double target[rows][cols];
    int i,j;

    for(i = 0; i < rows; i++)
        for(j = 0; j < cols; j++)
            target[i][j] = source[i][j];

    printf("Source array:\n");
    print_arr(rows, cols, source);

    printf("Target array:\n");
    print_arr(rows, cols, target);
}

void print_arr(int rows, int cols, double arr[rows][cols])
{
    int i,j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
            printf("%5.2f ", arr[i][j]);
        putchar('\n');
    }
}
