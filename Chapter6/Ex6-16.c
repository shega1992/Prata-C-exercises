#include <stdio.h>

int main(void)
{
    float Daphne_sum = 100.00;
    float Deidre_sum = 100.00;
    unsigned short int years = 0;
    _Bool Daphne_has_more_money_than_Deidre = 1;

    while(Daphne_has_more_money_than_Deidre)
    {
        Daphne_has_more_money_than_Deidre = ((Daphne_sum += 100.00 * 0.1) > (Deidre_sum += Deidre_sum * 0.05));
        years ++;
    }

    printf("Daphne\'s investment is %f\n"
           "Deirdre\'s investment is %f\n"
           "years: %hu ",
           Daphne_sum, Deidre_sum, years);

    return 0;
}
