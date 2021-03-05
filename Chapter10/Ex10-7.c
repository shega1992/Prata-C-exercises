#include <stdio.h>
#define ROWS 2
#define COLS 5

void copy_ptrs(double target[], double source[] , double *end_of_source);
void print_target_array(const double target[][COLS], int rows);


int main(void)
{
    double source[ROWS][COLS] = { {1.1, 2.2, 3.3, 4.4, 5.5}, {6.6, 7.7, 8.8, 9.9, 10.10} };
    double target[ROWS][COLS];
    int i;

    for(i = 0; i < ROWS; i++)
        copy_ptrs(target[i], source[i], source[i] + COLS);

    printf("target:\n");
    print_target_array(target,ROWS);

    return 0;
}

void copy_ptrs(double target[], double source[] , double *end_of_source)
{
    while(source < end_of_source)
        *target++ = *source++;

}

void print_target_array(const double target[][COLS], int rows)
{
    int i,j;

    for(i = 0; i < rows; i++)
    {
       for(j = 0; j < COLS; j++)
            printf("%.1f ", target[i][j]);

         putchar('\n');
    }

}
