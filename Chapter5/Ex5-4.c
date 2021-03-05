#include <stdio.h>
#define CM_PER_FEET 30.48
#define CM_PER_INCH 2.54

int main(void)
{
    float height_in_cm;
    float inch;
    int feet;

    printf("Enter a height in centimeters: ");
    scanf("%f", &height_in_cm);

    while(height_in_cm >0)
    {
        feet = height_in_cm / CM_PER_FEET;
        inch = (height_in_cm - feet * CM_PER_FEET) / CM_PER_INCH;
        printf("%.1f cm = %d feet, %.1f inches\n",
               height_in_cm, feet, inch);

        printf("Enter a height in centimeters (<=0 to quit): ");
        scanf("%f", &height_in_cm);
    }

    printf("Done!\n");
    return 0;
}
