#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "header.h"

void fill_id_and_status_field(FLIGHT aircraft[], int n)
{
    unsigned short int i;
    char pad = 'A';

    for(i = 0; i < n; i++)
    {
        aircraft[i].id = pad;
        aircraft[i].status = false;
        aircraft[i].confirmation = false;
        pad++;
    }
}

void show_menu(void)
{
    puts("**********************************************");
    printf("Please select a flight:\n"
           "0) 102\n"
           "1) 311\n"
           "2) 444\n"
           "3) 519\n"
           "4) Quit\n");
    puts("**********************************************");
}

int number_of_flight_is_correct(int number_of_flight)
{
    while(number_of_flight < 0 || number_of_flight > 3)
    {
        printf("You've entered incorrect value for flight\n"
               "There are next flights in list:\n"
               "0) 102\n"
               "1) 311\n"
               "2) 444\n"
               "3) 519\n"
               "Please select the option from 0 to 3: ");
        scanf("%d", &number_of_flight);
    }

    return number_of_flight;
}

void show_sub_menu(void)
{
    puts("**********************************************");
    printf("To choose a function, enter its letter label:\n"
           "a) Show number of empty seats\n"
           "b) Show list of empty seats\n"
           "c) Show alphabetical list of seats\n"
           "d) Assign a customer to a seat assignment\n"
           "e) Confirm a seat assignment\n"
           "f) Delete a seat assignment\n"
           "g) Return to main menu\n");
    puts("**********************************************");
}

void print_number_of_flight(int number_of_flight)
{
    puts("**********************************************");
    switch(number_of_flight)
    {
        case 0:
            puts("FLIGHT 102");
            break;
        case 1:
            puts("FLIGHT 311");
            break;
        case 2:
            puts("FLIGHT 444");
            break;
        case 3:
            puts("FLIGHT 519");
            break;
    }
}

void number_of_empty_seats(FLIGHT seats[], int n)
{
    unsigned short int i;
    unsigned short int count = 0;

    for(i = 0; i < n; i++)
        if(seats[i].status == 0)
            count++;

    printf("Number of empty seats: %hu\n", count);
}

void show_list_of_empty_seats(FLIGHT seats[], int n)
{
    unsigned short int i;

    puts("List of empty seats: ");
    for(i = 0; i < n; i++)
        if(seats[i].status == 0)
            printf("%c ", seats[i].id);
    putchar('\n');
}

void show_alphabetical_list_of_seats(FLIGHT seats[], int n)
{
    char list_of_seats[CAPACITY];
    unsigned short int i;

    for(i = 0; i < n; i++)
    {
        if(seats[i].status == 1)
            list_of_seats[i] = seats[i].id;
        else
            list_of_seats[i] = '0';
    }

    printf("Alphabetical_list_of_seats:\n");
    for(i = 0; i < n; i++)
        if(list_of_seats[i] != '0')
        {
            (seats[i].confirmation == 1)? printf("%c - confirmed\n", list_of_seats[i]) : printf("%c - not confirmed\n", list_of_seats[i]);
        }
    putchar('\n');
}

void assign_a_customer_to_a_seat_assignment(FLIGHT seats[], int n)
{
    unsigned short int i;
    char selection;

    puts("List of empty seats: ");
    for(i = 0; i < n; i++)
        if(seats[i].status == 0)
            printf("%c ", seats[i].id);

    eatline();
    printf("\nPlease select the seat from list: ");
    scanf("%c", &selection);

    for(i = 0; i < n; i++)
    {
        if(selection == seats[i].id)
        {
            if(seats[i].status == 0)
            {
                printf("Please enter your first name: ");
                scanf("%19s", seats[i].first_name);
                printf("Please enter your last name: ");
                scanf("%19s", seats[i].last_name);

                printf("The seat will be assigned to %s %s\n", seats[i].first_name, seats[i].last_name);
                seats[i].status = 1;
                break;
            }
            else
            {
                printf("The seat has already been assigned to other passenger\n");
                break;
            }

        }
    }

    if(i == n)
        puts("You've entered incorrect option for seat");
}

void confirm_a_seat_assignment(FLIGHT seats[], int n)
{
    char first[NLEN];
    char last[NLEN];
    unsigned short int i;
    char selection;

    printf("Please enter your first name: ");
    scanf("%19s", first);
    printf("Please enter your last name: ");
    scanf("%19s", last);

    for(i = 0; i < n; i++)
    {
        if(strcmp(seats[i].first_name, first) == 0 && strcmp(seats[i].last_name, last) == 0)
        {
           eatline();
           printf("%s %s, your seat: %c\n", seats[i].first_name, seats[i].last_name, seats[i].id);
           printf("Do you want to confirm your seat assignment(y/n): ");
           scanf("%c", &selection);

           if(selection == 'y')
           {
               puts("Your seat assignment has been confirmed");
               seats[i].confirmation = 1;
               break;
           }
           else if(selection == 'n')
           {
               puts("Return to the menu");
               break;
           }
           else
           {
               puts("You've selected incorrect option. Return to the menu");
               break;
           }

        }
    }

    if(i == n)
        printf("%s %s has not been found on the plane's passenger list\n", first, last);
}

void delete_a_seat_assignment(FLIGHT seats[], int n)
{
    char first[NLEN];
    char last[NLEN];
    unsigned short int i,j;
    char selection;

    printf("Please enter your first name: ");
    scanf("%19s", first);
    printf("Please enter your last name: ");
    scanf("%19s", last);


    for(i = 0; i < n; i++)
    {
        if(strcmp(seats[i].first_name, first) == 0 && strcmp(seats[i].last_name, last) == 0)
        {
           eatline();
           printf("%s %s, your seat: %c\n", seats[i].first_name, seats[i].last_name, seats[i].id);
           printf("Do you want to delete your seat assignment(y/n): ");
           scanf("%c", &selection);

           if(selection == 'y')
           {
               (seats[i].confirmation == 1)? puts("Your seat assignment and confirmation have been deleted") : puts("Your seat assignment has been deleted");
               for(j = 0; j < NLEN; j++)
               {
                   seats[i].first_name[j] = '\0';
                   seats[i].last_name[j] = '\0';
               }
               seats[i].status = 0;
               seats[i].confirmation = 0;
               break;
           }
           else if(selection == 'n')
           {
               puts("Return to the menu");
               break;
           }
           else
           {
               puts("You've selected incorrect option. Return to the menu");
               break;
           }

        }
    }

    if(i == n)
        printf("%s %s has not been found on the plane's passenger list\n", first, last);
}

void eatline(void)
{
    while(getchar() != '\n')
        continue;
}
