#include <stdio.h>
#include<stdbool.h>
#define PAY_RATE_1 8.75
#define PAY_RATE_2 9.33
#define PAY_RATE_3 10.00
#define PAY_RATE_4 11.20
#define OVERTIME 1.5
#define TAX_RATE_OF_THE_FIRST_300 0.15
#define TAX_RATE_OF_THE_NEXT_150 0.2
#define TAX_RATE_OF_THE_REST 0.25

int main(void)
{
    float gross_pay;
    float taxes;
    float net_pay;
    unsigned short int hours_worked_in_a_week;
    char selection;
    bool loop_is_executed = true;

    while(loop_is_executed)
    {
        printf("*****************************************************************\n");
        printf("Enter the number corresponding to the desired pay rate or action:\n"
               "a) $8.75/hr\t" "b) $9.33/hr\n"
               "c) $10.00/hr\t" "d) $11.20/hr\n"
               "q) quit\n");
        printf("*****************************************************************\n");
        scanf("%c", &selection);

        switch(selection)
        {
            case 'a':
                printf("Please enter hours worked in a week: ");
                scanf("%hu", &hours_worked_in_a_week);

                gross_pay = (hours_worked_in_a_week > 40)?
                40 * PAY_RATE_1 + (hours_worked_in_a_week - 40) * PAY_RATE_1 * OVERTIME:
                hours_worked_in_a_week * PAY_RATE_1;

                if(gross_pay <= 300)
                    taxes = gross_pay * TAX_RATE_OF_THE_FIRST_300;
                else if(gross_pay <=450)
                    taxes = 300 * TAX_RATE_OF_THE_FIRST_300 + (gross_pay - 300) * TAX_RATE_OF_THE_NEXT_150;
                else
                    taxes = 300 * TAX_RATE_OF_THE_FIRST_300 +
                    150 * TAX_RATE_OF_THE_NEXT_150 +
                    (gross_pay - 450) * TAX_RATE_OF_THE_REST;

                net_pay = gross_pay - taxes;

                printf("Gross pay: %.2f\n"
                       "Taxes: %.2f\n"
                       "Net pay: %.2f\n",
                       gross_pay, taxes, net_pay);
                break;
            case 'b':
                printf("Please enter hours worked in a week: ");
                scanf("%hu", &hours_worked_in_a_week);

                gross_pay = (hours_worked_in_a_week > 40)?
                40 * PAY_RATE_2 + (hours_worked_in_a_week - 40) * PAY_RATE_2 * OVERTIME:
                hours_worked_in_a_week * PAY_RATE_2;

                if(gross_pay <= 300)
                    taxes = gross_pay * TAX_RATE_OF_THE_FIRST_300;
                else if(gross_pay <=450)
                    taxes = 300 * TAX_RATE_OF_THE_FIRST_300 + (gross_pay - 300) * TAX_RATE_OF_THE_NEXT_150;
                else
                    taxes = 300 * TAX_RATE_OF_THE_FIRST_300 +
                    150 * TAX_RATE_OF_THE_NEXT_150 +
                    (gross_pay - 450) * TAX_RATE_OF_THE_REST;

                net_pay = gross_pay - taxes;

                printf("Gross pay: %.2f\n"
                       "Taxes: %.2f\n"
                       "Net pay: %.2f\n",
                       gross_pay, taxes, net_pay);
                break;
            case 'c':
                printf("Please enter hours worked in a week: ");
                scanf("%hu", &hours_worked_in_a_week);

                gross_pay = (hours_worked_in_a_week > 40)?
                40 * PAY_RATE_3 + (hours_worked_in_a_week - 40) * PAY_RATE_3 * OVERTIME:
                hours_worked_in_a_week * PAY_RATE_3;

                if(gross_pay <= 300)
                    taxes = gross_pay * TAX_RATE_OF_THE_FIRST_300;
                else if(gross_pay <=450)
                    taxes = 300 * TAX_RATE_OF_THE_FIRST_300 + (gross_pay - 300) * TAX_RATE_OF_THE_NEXT_150;
                else
                    taxes = 300 * TAX_RATE_OF_THE_FIRST_300 +
                    150 * TAX_RATE_OF_THE_NEXT_150 +
                    (gross_pay - 450) * TAX_RATE_OF_THE_REST;

                net_pay = gross_pay - taxes;

                printf("Gross pay: %.2f\n"
                       "Taxes: %.2f\n"
                       "Net pay: %.2f\n",
                       gross_pay, taxes, net_pay);
                break;
            case 'd':
                printf("Please enter hours worked in a week: ");
                scanf("%hu", &hours_worked_in_a_week);

                gross_pay = (hours_worked_in_a_week > 40)?
                40 * PAY_RATE_4 + (hours_worked_in_a_week - 40) * PAY_RATE_4 * OVERTIME:
                hours_worked_in_a_week * PAY_RATE_4;

                if(gross_pay <= 300)
                    taxes = gross_pay * TAX_RATE_OF_THE_FIRST_300;
                else if(gross_pay <=450)
                    taxes = 300 * TAX_RATE_OF_THE_FIRST_300 + (gross_pay - 300) * TAX_RATE_OF_THE_NEXT_150;
                else
                    taxes = 300 * TAX_RATE_OF_THE_FIRST_300 +
                    150 * TAX_RATE_OF_THE_NEXT_150 +
                    (gross_pay - 450) * TAX_RATE_OF_THE_REST;

                net_pay = gross_pay - taxes;

                printf("Gross pay: %.2f\n"
                       "Taxes: %.2f\n"
                       "Net pay: %.2f\n",
                       gross_pay, taxes, net_pay);
                break;
            case 'q':
                loop_is_executed = false;
                printf("The program has been completed\n");
                break;
            default:
                printf("Incorrect input. Please try again\n");
                break;
        }
        while(getchar() != '\n')
            continue;
    }

    return 0;
}

