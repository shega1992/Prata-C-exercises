#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define SIZE 10

void fill_the_source_array(double source[], int n);
void transform(double source[], double target[], int n, double (*fp)(double));
double square(double );
double cube(double );

int main(void)
{
    double source[SIZE];
    double target[SIZE];
    double (*fp)(double );

    srand(time(NULL));
    fill_the_source_array(source, SIZE);

    printf("Source array: ");
    for(int i = 0; i < SIZE; i++)
        printf("%.1f ", source[i]);
    putchar('\n');

    puts("Target array: ");
    for(int index = 1; index <= 4; index++)
    {
        switch(index)
        {
            case 1:
                fp = square;
                break;
            case 2:
                fp = cube;
                break;
            case 3:
                fp = sqrt;
                break;
            case 4:
                fp = fabs;
                break;

        }
        transform(source, target, SIZE, fp);

        printf("%d call: ", index);
        for(int i = 0; i < SIZE; i++)
            printf("%9.1f ", target[i]);
        putchar('\n');
    }

    return 0;
}

void fill_the_source_array(double source[], int n)
{
    int i;

    for(i = 0; i < n; i++)
        source[i] = rand() % 100 + 1;
}

void transform(double source[], double target[], int n, double (*fp)(double))
{
    int i;

    for(i = 0; i < n; i++)
        target[i] = (*fp)(source[i]);
}

double square(double value)
{
    return value * value;
}

double cube(double value)
{
    return value * value * value;
}
