#include <stdio.h>

int main(void)
{
    int my_number;

    printf("Please enter the number: ");
    scanf("%d", &my_number);

    int index = my_number + 10;
    while(my_number <= index){
        printf("%d ", my_number);
        my_number++;
    }

    return 0;
}
