#include <stdio.h>
#define ROWS 3
#define COLS 5

void multiply_by_2(int arr[][COLS], int rows);
void print_arr(const int arr[][COLS], int rows);

int main(void)
{
    int arr[ROWS][COLS];
    int i,j;

    for(i = 0; i < ROWS; i++)
    {
        printf("Please enter values of %d row: ", i);
        for(j = 0; j< COLS; j++)
            scanf("%d", &arr[i][j]);

        putchar('\n');
    }

    printf("Source array:\n");
    print_arr(arr, ROWS);

    multiply_by_2(arr, ROWS);

    printf("Array after multiply_by_2:\n");
    print_arr(arr, ROWS);

    return 0;
}

void multiply_by_2(int arr[][COLS], int rows)
{
    int i,j;

    for(i = 0; i < rows; i++)
        for(j = 0; j < COLS; j++)
            arr[i][j] *= 2;

}

void print_arr(const int arr[][COLS], int rows)
{
    int i,j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < COLS; j++)
            printf("%4d ", arr[i][j]);
        putchar('\n');
    }

}
