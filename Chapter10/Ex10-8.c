#include <stdio.h>

void copy_arr(double target[], double source[], unsigned short int n);
void print_target_array(const double target[], unsigned short int n);

int main(void)
{
    double source[7] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    double target [3];

    copy_arr(target, source, 3);

    return 0;
}

void copy_arr(double target[], double source[], unsigned short int n)
{
    int i,j;

    for(i = 2, j = 0; j < n; i++, j++)
        target[j] = source[i];

    printf("target: ");
    print_target_array(target,n);

}

void print_target_array(const double target[], unsigned short int n)
{
    int i;

    for(i = 0; i < n; i++)
        printf("%.1f ", target[i]);

    putchar('\n');

}
