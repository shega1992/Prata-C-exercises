#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
#define N 5

struct names{
    char first_name[SIZE];
    char middle_name[SIZE];
    char last_name[SIZE];
};

struct info{
    int social_security_number;
    struct names name;
};

void print_original_structure(const struct info *);
void print_copy_of_structure(struct info person);

int main(void)
{
    struct info people[N] = {
        {123456789, {"Marvin", "The", "Martian"}},
		{987654321, {"Scrooge", "Mc", "Duck"}},
		{888777666, {"Mantis", "Froggy", "Tobogan"}},
		{123432467, {.first_name ="Night", .last_name = "Man"}},
		{354257623, {.first_name ="Day", .last_name = "Man"}}
    };

    for(int i = 0; i < N; i++)
        print_original_structure(&people[i]);

    putchar('\n');

    for(int i = 0; i < N; i++)
        print_copy_of_structure(people[i]);


    return 0;
}

void print_original_structure(const struct info *person)
{
    printf("%s, %s ", person -> name.last_name, person ->name.first_name);
    if(person ->name.middle_name[0] != '\0')
        printf("%c. ", person -> name.middle_name[0]);
    printf("-- %d\n", person ->social_security_number);
}

void print_copy_of_structure(struct info person)
{
    printf("%s, %s ", person.name.last_name, person.name.first_name);
    if(person.name.middle_name[0] != '\0')
        printf("%c. ", person.name.middle_name[0]);
    printf("-- %d\n", person.social_security_number);
}

