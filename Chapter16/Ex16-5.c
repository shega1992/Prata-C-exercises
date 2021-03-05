#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 30

void fill_array(int arr_of_int[], int n);
void print_array(int arr_of_int[], int n);
int get_number_of_picks(void);
void pick_the_elements(int arr_of_int[], int n, int number_of_picks);

int main(void)
{
    int arr_of_int[SIZE];
    int number_of_picks;

    srand(time(NULL));

    fill_array(arr_of_int, SIZE);

    fputs("Your array: ", stdout);
    print_array(arr_of_int, SIZE);

    number_of_picks = get_number_of_picks();

    pick_the_elements(arr_of_int, SIZE, number_of_picks);

    return 0;
}

void fill_array(int arr_of_int[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        arr_of_int[i] = i + 1;

}

void print_array(int arr_of_int[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        printf("%d ", arr_of_int[i]);
    putchar('\n');
}

int get_number_of_picks(void)
{
    int number_of_picks;

    printf("Please enter number of picks: ");

    while(scanf("%d", &number_of_picks) != 1 || number_of_picks < 0 || number_of_picks >  SIZE)
    {
        printf("You've entered incorrect value for number of picks"
               "Please enter the value from 0 to %d: ", SIZE);

        while(getchar() != '\n')
            continue;
    }

    return number_of_picks;
}

void pick_the_elements(int arr_of_int[], int n, int number_of_picks)
{
    int i = 0;
    int random_index;

    while(i < number_of_picks)
    {
        random_index = rand() % SIZE;
        if(arr_of_int[random_index] != 0)
        {
            printf("Number from array: %d\n", arr_of_int[random_index]);
            i++;
        }

        arr_of_int[random_index] = 0; // substitution for picked elements in array
    }

}
