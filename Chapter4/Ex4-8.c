#include <stdio.h>

int main(void)
{
    const float one_mile_to_kilometers = 1.609;
    const float one_gallon_to_liters = 3.785;

    float number_of_miles_traveled, number_of_gallons_of_gasoline_consumed;

    printf("Please enter the number of miles traveled \
and the number of gallons of gasoline consumed: ");
    scanf("%f %f", &number_of_miles_traveled, &number_of_gallons_of_gasoline_consumed);

    printf("Miles-per-gallon value: %.1f\n",
           number_of_miles_traveled / number_of_gallons_of_gasoline_consumed);
    printf("Liters-per-100-km value: %.1f\n",
           (number_of_gallons_of_gasoline_consumed * one_gallon_to_liters)/(number_of_miles_traveled * one_mile_to_kilometers) * 100);

    return 0;
}
