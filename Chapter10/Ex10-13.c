#include <stdio.h>
#define ROWS 3
#define COLS 5

void store_the_information_in_array(double arr[][COLS], int rows);
double average_for_set_five_values(double arr[], int n);
double average_of_all_the_values(double arr[][COLS], int rows);
double largest_value_of_the_15_values(double arr[][COLS], int rows);
void print_result(double number);
void print_arr(double arr[][COLS], int rows); // optional for this task

int main(void)
{
    double arr[ROWS][COLS];
    int i;

    store_the_information_in_array(arr, ROWS);

    for(i = 0; i < ROWS; i++)
    {
        printf("Average for %d row: ", i);
        print_result(average_for_set_five_values(arr[i], COLS));

    }

    printf("Average of all the values: ");
    print_result(average_of_all_the_values(arr, ROWS));

    printf("Largest_value_of_the_15_values: ");
    print_result(largest_value_of_the_15_values(arr, ROWS));

    return 0;
}

void store_the_information_in_array(double arr[][COLS], int rows)
{
    int i,j;

    for(i = 0; i < rows; i++)
    {
        printf("Please enter values of %d row: ", i);
        for(j = 0; j< COLS; j++)
            scanf("%lf", &arr[i][j]);

        putchar('\n');
    }

    printf("Your array:\n");
    print_arr(arr, ROWS);
}


double average_for_set_five_values(double arr[], int n)
{
    double sum_of_row = 0;
    int i;

    for(i = 0; i < n; i++)
        sum_of_row += arr[i];

    return sum_of_row / n;

}

double average_of_all_the_values(double arr[][COLS], int rows)
{
    double sum_of_all_the_values = 0;
    int i,j;

    for(i = 0; i < rows; i++)
        for(j = 0; j < COLS; j++)
            sum_of_all_the_values += arr[i][j];

    return sum_of_all_the_values / (rows * COLS);

}

double largest_value_of_the_15_values(double arr[][COLS], int rows)
{
    double max_value = arr[0][0];
    int i,j;

    for(i = 0; i < rows; i++)
        for(j = 0; j < COLS; j++)
        {
            if(arr[i][j] > max_value)
                max_value = arr[i][j];
        }

    return max_value;


}


void print_result(double number)
{
    printf("%f\n", number);
}

void print_arr(double arr[][COLS], int rows) // optional for this task
{
    int i,j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < COLS; j++)
            printf("%5.2f ", arr[i][j]);
        putchar('\n');
    }
    putchar('\n');
}

