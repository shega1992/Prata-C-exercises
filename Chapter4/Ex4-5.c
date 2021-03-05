#include <stdio.h>

int main(void)
{
    float download_speed, file_size;

    printf("Please enter the download speed in megabits per second and the size of a file in megabytes: ");
    scanf("%f %f", &download_speed, &file_size);

    printf("At %.2f megabits per second, a file of %.2f megabytes\ndownloads in %.2f seconds\n",
           download_speed, file_size, file_size * 8 / download_speed);

    return 0;
}
