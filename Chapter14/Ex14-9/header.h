
#define NLEN 20
#define NUMBER 4
#define CAPACITY 12
#define QUIT 4
#define RETURN_TO_MAIN_MENU 'g'

typedef struct flight{
    char first_name[NLEN];
    char last_name[NLEN];
    char id;
    bool status; // busy - 1; free - 0
    bool confirmation; // Yes - 1; No - 0
}FLIGHT;

void fill_id_and_status_field(FLIGHT aircraft[], int n); // initial initialization for these fields
void show_menu(void);
int number_of_flight_is_correct(int number_of_flight);
void show_sub_menu(void);
void print_number_of_flight(int number_of_flight);
void number_of_empty_seats(FLIGHT seats[], int n);
void show_list_of_empty_seats(FLIGHT seats[], int n);
void show_alphabetical_list_of_seats(FLIGHT seats[], int n);
void assign_a_customer_to_a_seat_assignment(FLIGHT seats[], int n);
void confirm_a_seat_assignment(FLIGHT seats[], int n);
void delete_a_seat_assignment(FLIGHT seats[], int n);
void eatline(void);
