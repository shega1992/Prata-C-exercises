#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "header.h"

int main(void)
{
    FLIGHT aircraft[CAPACITY];
    int index;
    int size = sizeof (FLIGHT);
    FILE * p_aircraft;
    char selection;

    if ((p_aircraft = fopen("aircraft.dat", "rb")) == NULL)
    {
        fputs("Can't open aircraft.dat file for reading\n",stderr);
        exit(1);
    }

    if(fread(aircraft, size, CAPACITY, p_aircraft) == 0)
        fill_id_and_status_field(aircraft, CAPACITY);

    if(fclose(p_aircraft) != 0)
    {
        fputs("Error in closing file aircraft.dat(reading)\n", stderr);
        exit(1);
    }

    show_menu();

    while(scanf("%c", &selection) && selection != QUIT)
    {
        switch(selection)
        {
            case 'a':
                number_of_empty_seats(aircraft, CAPACITY);
                break;
            case 'b':
                show_list_of_empty_seats(aircraft, CAPACITY);
                break;
            case 'c':
                show_alphabetical_list_of_seats(aircraft, CAPACITY);
                break;
            case 'd':
                assign_a_customer_to_a_seat_assignment(aircraft, CAPACITY);
                break;
            case 'e':
                delete_a_seat_assignment(aircraft, CAPACITY);
                break;
            default:
                printf("You've selected incorrect option\n"
                       "Please enter the option from \'a\' to \'f\'\n");
                break;
        }

        eatline();
        show_menu();
    }

    if ((p_aircraft = fopen("aircraft.dat", "wb")) == NULL)
    {
        fputs("Can't open aircraft.dat file for writing\n",stderr);
        exit(1);
    }


    for(index = 0; index < CAPACITY; index++)
        fwrite(&aircraft[index], size, 1 ,p_aircraft);

    if(fclose(p_aircraft) != 0)
    {
        fputs("Error in closing file aircraft.dat(writing)\n", stderr);
        exit(1);
    }

    return 0;
}


