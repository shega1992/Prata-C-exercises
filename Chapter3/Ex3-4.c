#include <stdio.h>

int main(void)
{
    float my_value;

    printf("Enter a floating-point value: ");
    scanf("%f", &my_value);
    printf("fixed-point notation: %f\n", my_value);
    printf("exponential notation: %e\n",my_value);
    printf("p notation: %a\n", my_value);
    return 0;
}
