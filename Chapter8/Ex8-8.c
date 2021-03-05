#include <stdio.h>
#include<stdbool.h>

float input_is_good(void);
float number_other_than_0(float number);

int main(void)
{
    float x,y;
    char selection;
    bool loop_is_executed = true;

    while(loop_is_executed)
    {
        printf("*************************************\n");
        printf("Enter the operation of your choice:\n"
           "a. add\t\t" "s. subtract\n"
           "m. multiply\t" "d. divide\n"
           "q. quit\n");
         printf("*************************************\n");
           scanf("%c", &selection);

        switch(selection)
        {
            case 'a':
                printf("Enter first number: ");
                x = input_is_good();
                printf("Enter second number: ");
                y = input_is_good();
                printf("%f + %f = %f\n", x, y, x+y);
                break;
            case 's':
                printf("Enter first number: ");
                x = input_is_good();
                printf("Enter second number: ");
                y = input_is_good();
                printf("%f - %f = %f\n", x, y, x-y);
                break;
            case 'm':
                printf("Enter first number: ");
                x = input_is_good();
                printf("Enter second number: ");
                y = input_is_good();
                printf("%f * %f = %f\n", x, y, x*y);
                break;
            case 'd':
                printf("Enter first number: ");
                x = input_is_good();
                printf("Enter second number: ");
                y = input_is_good();
                if(y == 0)
                    y = number_other_than_0(y);
                printf("%f / %f = %f\n", x, y, x/y);
                break;
            case 'q':
                printf("Bye\n");
                loop_is_executed = false;
                break;
            default:
                printf("Incorrect operation. Please try again\n");
                break;
        }

        while(getchar() !='\n')
            continue;
    }

    return 0;
}

float input_is_good(void)
{
    float input;
    char ch;
    while (scanf("%f", &input) != 1)
        {
            while ((ch = getchar()) != '\n')
                putchar(ch); // dispose of bad input
            printf(" is not an float.\nPlease enter an ");
            printf("floating point value, such as -2.5, -1.78E8, or 3: ");
        }

    return input;

}

float number_other_than_0(float number)
{
    while(number == 0)
    {
       printf("Enter a number other than 0: ");
       scanf("%f", &number);
    }

    return number;
}





