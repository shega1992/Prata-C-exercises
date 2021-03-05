// pe12-3b.c
// compile with pe12-2a.c
#include <stdio.h>
#include "pe12-3a.h"

int main(void)
{
    int mode;
    int previous_mode = 0;
    float distance;
    float fuel_consumption;
    printf("Enter 0 for metric mode, 1 for US mode: ");
    scanf("%d", &mode);
    while (mode >= 0)
    {
        mode = set_mode(mode, &previous_mode);
        get_info(&distance, &fuel_consumption, mode);
        show_info(&distance, &fuel_consumption, mode);
        printf("Enter 0 for metric mode, 1 for US mode");
        printf(" (-1 to quit): ");
        scanf("%d", &mode);
    }
    printf("Done.\n");
    return 0;
}
