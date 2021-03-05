#include <stdio.h>


int main(void)
{
    float volume_in_cups;

    printf("Please enter a volume in cups: ");
    scanf("%f", &volume_in_cups);
    printf("The volume in pints is %f\n", volume_in_cups / 2);
    printf("The volume in ounces is %f\n", volume_in_cups * 8);
    printf("The volume in tablespoons is %f\n", volume_in_cups * 8 * 2);
    printf("The volume in teaspoons is %f\n", volume_in_cups * 8 * 2 * 3);
    return 0;
}
