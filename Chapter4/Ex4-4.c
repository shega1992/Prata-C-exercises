#include <stdio.h>

int main(void)
{
    float height;
    char name[40];

    printf("Please enter your height in centimeters and your name: ");
    scanf("%f %s", &height, name);

    printf("%s, your height is %.2f meters\n", name, height/100);

    return 0;
}
