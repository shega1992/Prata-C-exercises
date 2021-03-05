#include <stdio.h>

void chline(char , unsigned int , unsigned int);
void discard_the_input(void);

int main(void)
{
    unsigned int begin, end;
    char character;

    printf("Please enter your character and start and end of range: ");

    while(scanf("%c %u %u", &character, &begin, &end) == 3)
    {
        (begin > end)?
        printf("Incorrect values of begin and end.\n") :
            chline(character, begin, end);

        discard_the_input();

        printf("Do you want to continue? Type any key to continue and Ctrl+z for exit: ");
        if(getchar() == EOF)
            break;

        discard_the_input();

        printf("Please enter your character and start and end of range: ");
    }

    printf("The program has been completed");

    return 0;
}

void chline(char ch, unsigned int i, unsigned int j)
{
    unsigned int number_of_columns;
    unsigned int number_of_spaces;

        for(number_of_columns = 0; number_of_columns <= j; number_of_columns++)
            printf("%3u", number_of_columns);
        putchar('\n');


        for(number_of_spaces = 0 ; number_of_spaces < i; number_of_spaces++)
            printf("   ");

         for(; i <= j; i++)
            printf("%3c", ch);

         printf("\n");
    }


void discard_the_input(void)
{
    while(getchar() != '\n')
            continue;
}





