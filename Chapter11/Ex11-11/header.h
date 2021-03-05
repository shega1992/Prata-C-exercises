#define NUMBER_OF_STRINGS 10
#define NUMBER_OF_CHARACTERS_IN_STRING 40
#define QUIT 5

char * s_gets(char * st, int n);
int menu(void);
void print_the_list_of_strings(char st[][NUMBER_OF_CHARACTERS_IN_STRING], int rows);
void sort_the_strings_in_ASCII_collating_sequence(char *st[], int rows);
void sort_the_strings_in_order_of_increasing_length(char *st[], int rows);
void sort_the_strings_in_order_of_the_length_of_the_first_word_in_the_string(char *st[], int rows);
char *find_first_whitespace_or_punctuation_character(char *st);
