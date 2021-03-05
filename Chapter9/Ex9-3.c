#include <stdio.h>

void print_character(char, unsigned int , unsigned int );
void discard_the_input(void);

int main(void)
{
    unsigned int rows, cols;
    char character;

    printf("Please enter your character and number of rows and columns: ");

    while(scanf("%c %u %u", &character, &rows, &cols) == 3)
    {
        print_character(character, rows, cols);

        printf("Do you want to continue? Please type any key to continue and Ctrl+z for exit: ");

        if(getchar() == EOF)
            break;

        discard_the_input();

        printf("Please enter next character and number of rows and columns: ");
    }

    printf("Program has been completed");

    return 0;
}

void print_character(char character, unsigned int rows, unsigned int cols)
{
    int i,j;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
            printf("%c ", character);

        printf("\n");
    }

    discard_the_input();
}

void discard_the_input(void)
{
    while(getchar() != '\n')
        continue;
}
