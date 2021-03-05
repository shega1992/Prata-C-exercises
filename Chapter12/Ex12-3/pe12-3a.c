// pe12-3a.c
#include <stdio.h>
#include "pe12-3a.h"



int set_mode(int mode,int *previous_mode)
{
    if(mode > 1)
    {
         printf("Invalid mode specified. Mode %d used\n", *previous_mode);
         return *previous_mode;
    }
    else
    {
         *previous_mode = mode;
         return mode;
    }

}

void get_info(float *distance, float *fuel_consumption, int mode)
{
    switch(mode)
    {
        case 0:
            fputs("Enter distance traveled in kilometers: ", stdout);
            scanf("%f", distance);
            fputs("Enter fuel consumed in liters:", stdout);
            scanf("%f", fuel_consumption);
            break;
        case 1:
            fputs("Enter distance traveled in miles: ", stdout);
            scanf("%f", distance);
            fputs("Enter fuel consumed in gallons: ", stdout);
            scanf("%f", fuel_consumption);
            break;
    }
}

void show_info(float *distance, float *fuel_consumption, int mode)
{
    switch(mode)
    {
        case 0:
            printf("Fuel consumption is %f liters per 100 km.\n", (*fuel_consumption)/(*distance) * 100);
            break;
        case 1:
            printf("Fuel consumption is %f miles per gallon.\n", (*distance)/(*fuel_consumption));
            break;
    }
}
