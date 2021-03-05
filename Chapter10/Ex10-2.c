#include <stdio.h>

void copy_arr(double target[], double source[], unsigned short int n);
void copy_ptr(double target[], double source[], unsigned short int n);
void copy_ptrs(double target[], double source[] , double *end_of_source);
void print_target_array(const double target[], unsigned short int n);


int main(void)
{
    double source[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
    double target1[5];
    double target2[5];
    double target3[5];

    copy_arr(target1, source, 5);
    copy_ptr(target2, source, 5);
    copy_ptrs(target3, source, source + 5);
    return 0;
}

void copy_arr(double target[], double source[], unsigned short int n)
{
    int i;

    for(i = 0; i < n; i++)
        target[i] = source[i];

    printf("target 1: ");
    print_target_array(target,n);

}

void copy_ptr(double target[], double source[], unsigned short int n)
{
    int i = 0;

    while(i < n)
    {
        *target++ = *source++;
        i++;

    }
    printf("target 2: ");
    print_target_array(target,n);
}

void copy_ptrs(double target[], double source[] , double *end_of_source)
{
    while(source < end_of_source)
        *target++ = *source++;

    printf("target 3: ");
    print_target_array(target,5);
}


void print_target_array(const double target[], unsigned short int n)
{
    int i;

    for(i = 0; i < n; i++)
        printf("%.1f ", target[i]);

    putchar('\n');

}
