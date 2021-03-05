#include <stdio.h>

int main()
{
    char letter;
    char first_uppercase_letter;

    printf("Please enter an uppercase letter: ");
    scanf("%c", &letter);

    short NUMBER_OF_SPACES;
    short index;
    short ascending_order_limiter = 1;
    short descending_order_limiter = 0;


    while(letter >= 'A')
    {
        for(NUMBER_OF_SPACES = letter - 'A'; NUMBER_OF_SPACES > 0; NUMBER_OF_SPACES --)
            printf(" ");

        for(index = 0, first_uppercase_letter = 'A'; index < ascending_order_limiter; index++ )
            printf("%c", first_uppercase_letter++);

        first_uppercase_letter-=2;

        for(index = 0; index < descending_order_limiter; index++)
            printf("%c", first_uppercase_letter--);

        printf("\n");
        ascending_order_limiter++;
        descending_order_limiter++;
        letter--;
    }


    return 0;
}


