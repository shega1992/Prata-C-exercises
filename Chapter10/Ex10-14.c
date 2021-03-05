#include <stdio.h>
#define ROWS 3
#define COLS 5

void store_the_information_in_array(int rows, int cols, double arr[rows][cols]);
double average_for_set_five_values(int n, double arr[n]);
double average_of_all_the_values(int rows, int cols, double arr[rows][cols]);
double largest_value_of_the_15_values(int rows, int cols, double arr[rows][cols]);
void print_result(double number);
void print_arr(int rows, int cols, double arr[rows][cols]); // optional for this task

int main(void)
{
    double arr[ROWS][COLS];
    int i;

    store_the_information_in_array(ROWS, COLS, arr);

    for(i = 0; i < ROWS; i++)
    {
        printf("Average for %d row: ", i);
        print_result(average_for_set_five_values(COLS, arr[i]));

    }

    printf("Average of all the values: ");
    print_result(average_of_all_the_values(ROWS, COLS, arr));

    printf("Largest_value_of_the_15_values: ");
    print_result(largest_value_of_the_15_values(ROWS, COLS, arr));

    return 0;
}

void store_the_information_in_array(int rows, int cols, double arr[rows][cols])
{
    int i,j;

    for(i = 0; i < rows; i++)
    {
        printf("Please enter values of %d row: ", i);
        for(j = 0; j< cols; j++)
            scanf("%lf", &arr[i][j]);

        putchar('\n');
    }

    printf("Your array:\n");
    print_arr(rows, cols, arr);
}


double average_for_set_five_values(int n, double arr[n])
{
    double sum_of_row = 0;
    int i;

    for(i = 0; i < n; i++)
        sum_of_row += arr[i];

    return sum_of_row / n;

}

double average_of_all_the_values(int rows, int cols, double arr[rows][cols])
{
    double sum_of_all_the_values = 0;
    int i,j;

    for(i = 0; i < rows; i++)
        for(j = 0; j < cols; j++)
            sum_of_all_the_values += arr[i][j];

    return sum_of_all_the_values / (rows * cols);

}

double largest_value_of_the_15_values(int rows, int cols, double arr[rows][cols])
{
    double max_value = arr[0][0];
    int i,j;

    for(i = 0; i < rows; i++)
        for(j = 0; j < cols; j++)
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

void print_arr(int rows, int cols, double arr[rows][cols]) // optional for this task
{
    int i,j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
            printf("%5.2f ", arr[i][j]);
        putchar('\n');
    }
    putchar('\n');
}
