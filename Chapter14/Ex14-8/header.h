
#define NLEN 20
#define CAPACITY 12
#define QUIT 'f'

typedef struct flight{
    char first_name[NLEN];
    char last_name[NLEN];
    char id;
    bool status; // busy - 1; free - 0
}FLIGHT;

void fill_id_and_status_field(FLIGHT aircraft[], int n); // initial initialization for these fields
void show_menu(void);
void number_of_empty_seats(FLIGHT seats[], int n);
void show_list_of_empty_seats(FLIGHT seats[], int n);
void show_alphabetical_list_of_seats(FLIGHT seats[], int n);
void assign_a_customer_to_a_seat_assignment(FLIGHT seats[], int n);
void delete_a_seat_assignment(FLIGHT seats[], int n);
void eatline(void);
