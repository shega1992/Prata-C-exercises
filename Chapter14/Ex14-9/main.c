#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "header.h"

int main(void)
{
    FLIGHT aircraft[NUMBER][CAPACITY];
    int i,j;
    int number_of_flight;
    int size = sizeof (FLIGHT);
    FILE * p_aircraft;
    char selection;

    if ((p_aircraft = fopen("aircraft.dat", "rb")) == NULL)
    {
        fputs("Can't open aircraft.dat file for reading\n",stderr);
        exit(1);
    }

    for(i = 0; i < NUMBER; i++)
    {
        if(fread(aircraft[i], size, CAPACITY, p_aircraft) == 0)
            fill_id_and_status_field(aircraft[i], CAPACITY);
    }


    if(fclose(p_aircraft) != 0)
    {
        fputs("Error in closing file aircraft.dat(reading)\n", stderr);
        exit(1);
    }

    show_menu();

    while(scanf("%d", &number_of_flight) == 1 && number_of_flight != QUIT)
    {
        number_of_flight = number_of_flight_is_correct(number_of_flight);

        print_number_of_flight(number_of_flight);
        show_sub_menu();
        eatline();

        while(scanf("%c", &selection) && selection != RETURN_TO_MAIN_MENU)
        {
            switch(selection)
            {
            case 'a':
                number_of_empty_seats(aircraft[number_of_flight], CAPACITY);
                break;
            case 'b':
                show_list_of_empty_seats(aircraft[number_of_flight], CAPACITY);
                break;
            case 'c':
                show_alphabetical_list_of_seats(aircraft[number_of_flight], CAPACITY);
                break;
            case 'd':
                assign_a_customer_to_a_seat_assignment(aircraft[number_of_flight], CAPACITY);
                break;
            case 'e':
                confirm_a_seat_assignment(aircraft[number_of_flight], CAPACITY);
                break;
            case 'f':
                delete_a_seat_assignment(aircraft[number_of_flight], CAPACITY);
                break;
            default:
                printf("You've selected incorrect option\n"
                       "Please enter the option from \'a\' to \'g\'\n");
                break;
            }

            eatline();
            show_sub_menu();
        }

        show_menu();
    }

    if ((p_aircraft = fopen("aircraft.dat", "wb")) == NULL)
    {
        fputs("Can't open aircraft.dat file for writing\n",stderr);
        exit(1);
    }

    for(i = 0; i < NUMBER; i++)
    {
        for(j = 0; j < CAPACITY; j++)
            fwrite(&aircraft[i][j], size, 1 ,p_aircraft);
    }


    if(fclose(p_aircraft) != 0)
    {
        fputs("Error in closing file aircraft.dat(writing)\n", stderr);
        exit(1);
    }

    return 0;
}
