#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[40];

    printf("Please enter your name: ");
    scanf("%s", name);
    unsigned short int name_d = strlen(name) + 3; //  for d subtask

    printf("Name is enclosed in double quotation marks: \"%s\"\n" , name);
    printf("Name is in a field 20 characters wide and the name at the right end of the field: \"%20s\"\n", name);
    printf("Name is in a field 20 characters wide and the name at the left end of the field: \"%-20s\"\n", name);
    printf("Name is in a field three characters wider than the name: \"%*s\"\n", name_d, name);

    return 0;
}
