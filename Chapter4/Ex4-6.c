#include <stdio.h>
#include<string.h>

int main(void)
{
    char first_name[20];
    char last_name[20];

    printf("Please enter your first name and last name: ");
    scanf("%s %s", first_name, last_name);

    // Next two variables are not necessary. They are used for great expressiveness of code
    unsigned short int first_name_alignment = strlen(first_name);
    unsigned short int last_name_alignment = strlen(last_name);

    printf("%s %s\n", first_name, last_name);
    printf("%*hu %*hu\n", first_name_alignment, first_name_alignment, last_name_alignment, last_name_alignment);

    printf("%s %s\n", first_name, last_name);
    printf("%-*hu %-*hu\n", first_name_alignment, first_name_alignment, last_name_alignment, last_name_alignment);
    return 0;
}
