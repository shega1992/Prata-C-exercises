#include <stdio.h>

int main(void)
{
    float inches;

    printf("Please enter your height in inches: ");
    scanf("%f", &inches);
    // There are 2.54 centimeters to the inch
    printf("Your height in centimeters is %.1f", inches * 2.54);
    return 0;
}
