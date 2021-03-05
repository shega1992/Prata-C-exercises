// pe12-2a.c
#include <stdio.h>
#include "pe12-2a.h"

static int selected_mode;
static float distance;
static float fuel_consumption;

void set_mode(int mode)
{
    if(mode > 1)
         printf("Invalid mode specified. Mode %d used\n", selected_mode);
    else
        selected_mode = mode;
}

void get_info(void)
{
    switch(selected_mode)
    {
        case 0:
            fputs("Enter distance traveled in kilometers: ", stdout);
            scanf("%f", &distance);
            fputs("Enter fuel consumed in liters:", stdout);
            scanf("%f", &fuel_consumption);
            break;
        case 1:
            fputs("Enter distance traveled in miles: ", stdout);
            scanf("%f", &distance);
            fputs("Enter fuel consumed in gallons: ", stdout);
            scanf("%f", &fuel_consumption);
            break;
    }
}

void show_info(void)
{
    switch(selected_mode)
    {
        case 0:
            printf("Fuel consumption is %f liters per 100 km.\n", fuel_consumption/distance * 100);
            break;
        case 1:
            printf("Fuel consumption is %f miles per gallon.\n", distance/fuel_consumption);
            break;
    }
}
