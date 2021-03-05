#include <stdio.h>
#include <float.h>

int main(void)
{
    double value_of_double_type = 1.0/3.0;
    float value_of_float_type = 1.0 /3.0;

    printf("Let\'s start with Double type\n"
           "four digits to the right of the decimal: %.4f\n"
           "12 digits to the right of the decimal: %.12f\n"
           "16 digits to the right of the decimal: %.16f\n\n",
           value_of_double_type, value_of_double_type, value_of_double_type);

    printf("Next we will see how to display float type\n"
           "four digits to the right of the decimal: %.4f\n"
           "12 digits to the right of the decimal: %.12f\n"
           "16 digits to the right of the decimal: %.16f\n\n",
           value_of_float_type, value_of_float_type, value_of_float_type);

    printf("Minimum number of significant decimal digits for a float is %d\n", FLT_DIG);
    printf("Minimum number of significant decimal digits for a double is %d\n", DBL_DIG);

    return 0;
}
