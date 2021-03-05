#include <stdio.h>

int main(void)
{
    short age;

    printf("Please enter your age: ");
    scanf("%hd", &age);
    printf("Your age in seconds is: %f", age * 3.156E7);
    return 0;
}
