#include <stdio.h>

void discard_the_input(void);

int main(void)
{
    unsigned short int low_limit = 0;
    unsigned short int high_limit = 100;
    char response;

    printf("Pick an integer from 1 to 100. I will try to guess ");
    printf("it.\nRespond with a y if my guess is right and with");
    printf("\nan n if it is wrong.\n");
    printf("Uh...is your number %hu?\n", (low_limit + high_limit) / 2);

    while ((response = getchar()) != 'y')
    {
        if(response == 'n')
        {
            printf("Is your number greater than %hu? (y/n for answer): ");
            discard_the_input();
            if((response = getchar()) == 'y')
                low_limit = (low_limit + high_limit) / 2;
            else
                high_limit = (low_limit + high_limit) / 2;
        }
        else
            printf("Sorry, I understand only y or n.\n");

       discard_the_input();

        printf("Well, then, is it %hu?\n", (low_limit + high_limit) / 2);
    }

    printf("I knew I could do it!\n");

    return 0;
}

void discard_the_input(void)
{
    while (getchar() != '\n')
        continue;
}
