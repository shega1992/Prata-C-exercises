#include <stdio.h>

int main(void)
{
    float my_number;

    printf("Please enter a floating point number: ");
    scanf("%f", &my_number);

    printf("One digit to the right of the decimal point\n"
           "Your number in decimal-point notation: %.1f\nYour number in exponential notation: %.1e\n\n", my_number, my_number);
    printf("Three digits to the right of the decimal point\n"
           "Your number in decimal-point notation: %.3f\nYour number in exponential notation: %.3e\n", my_number, my_number);

    return 0;
}
