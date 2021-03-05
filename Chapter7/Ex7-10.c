#include <stdio.h>
#include<stdbool.h>
#define TAX 0.15
#define EXCESS_TAX 0.28

int main(void)
{
    unsigned int taxable_income;
    short selection;
    bool loop_is_executed = true;

    while(loop_is_executed)
    {
         printf("***************************************\n");
         printf("Please select tax category (5 for exit): \n"
           "1.Single\n"
           "2.Head of Household\n"
           "3.Married, Joint\n"
           "4.Married, Separate\n"
           "5.Exit\n");
         printf("***************************************\n");
           scanf("%hd", &selection);

           switch(selection)
           {
                case 1:
                    printf("Please enter the taxable income: ");
                    scanf("%u", &taxable_income);
                    if(taxable_income > 17850)
                        printf("Tax: %f\n", TAX * 17850 + EXCESS_TAX * (taxable_income - 17850));
                    else
                        printf("Tax: %f\n", TAX * taxable_income);
                    break;
                case 2:
                    printf("Please enter the taxable income: ");
                    scanf("%u", &taxable_income);
                    if(taxable_income > 23900)
                        printf("Tax: %f\n", TAX * 23900 + EXCESS_TAX * (taxable_income - 23900));
                    else
                        printf("Tax: %f\n", TAX * taxable_income);
                    break;
                case 3:
                    printf("Please enter the taxable income: ");
                    scanf("%u", &taxable_income);
                    if(taxable_income > 29750)
                        printf("Tax: %f\n", TAX * 29750 + EXCESS_TAX * (taxable_income - 29750));
                    else
                        printf("Tax: %f\n", TAX * taxable_income);
                    break;
                case 4:
                    printf("Please enter the taxable income: ");
                    scanf("%u", &taxable_income);
                    if(taxable_income > 14875)
                        printf("Tax: %f\n", TAX * 14875 + EXCESS_TAX * (taxable_income - 14875));
                    else
                        printf("Tax: %f\n", TAX * taxable_income);
                    break;
                case 5:
                    printf("The program has been completed\n");
                    loop_is_executed = false;
                    break;
                default:
                    printf("You select incorrect option\n");
                    break;
           }

    }

    return 0;
}
