#include <stdio.h>

int main(void)
{
    char first_name[20];
    char last_name[20];

    printf("Please enter your first name and your last name: ");
    scanf("%s %s", first_name, last_name);
    printf("last name: %s, first name: %s", last_name, first_name);

    return 0;
}
