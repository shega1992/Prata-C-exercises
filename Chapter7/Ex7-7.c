#include <stdio.h>
#define BASIC_PAY_RATE_IN_HOUR 10.0
#define OVERTIME 1.5
#define TAX_RATE_OF_THE_FIRST_300 0.15
#define TAX_RATE_OF_THE_NEXT_150 0.2
#define TAX_RATE_OF_THE_REST 0.25

int main(void)
{
    unsigned int gross_pay;
    float taxes;
    float net_pay;
    unsigned short int hours_worked_in_a_week;

    printf("Please enter the hours worked in a week: ");
    scanf("%hu", &hours_worked_in_a_week);

    gross_pay = (hours_worked_in_a_week > 40)?
    40 * BASIC_PAY_RATE_IN_HOUR + (hours_worked_in_a_week - 40) * BASIC_PAY_RATE_IN_HOUR * OVERTIME:
        hours_worked_in_a_week * BASIC_PAY_RATE_IN_HOUR;


    if(gross_pay <= 300)
        taxes = gross_pay * TAX_RATE_OF_THE_FIRST_300;
    else if(gross_pay <=450)
        taxes = 300 * TAX_RATE_OF_THE_FIRST_300 + (gross_pay - 300) * TAX_RATE_OF_THE_NEXT_150;
    else
        taxes = 300 * TAX_RATE_OF_THE_FIRST_300 +
        150 * TAX_RATE_OF_THE_NEXT_150 +
        (gross_pay - 450) * TAX_RATE_OF_THE_REST;

    net_pay = gross_pay - taxes;

    printf("Gross pay: %u\n"
           "Taxes: %.2f\n"
           "Net pay: %.2f\n",
           gross_pay, taxes, net_pay);

    return 0;
}
