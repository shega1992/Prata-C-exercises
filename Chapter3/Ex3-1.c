#include <stdio.h>
#include<limits.h>
#include<float.h>

int main(void)
{
    // This portion of code demonstrates some constants from limits.h
    printf("Number of bits in char is %d\nMinimum value is %d\nMaximum value is %d\n\n", CHAR_BIT,CHAR_MIN,CHAR_MAX);
    printf("The minimum value of short is %hd\nThe maximum value of short is %hd\n\n", SHRT_MIN,SHRT_MAX);
    printf("The minimum value of int is %d\nThe maximum value of int is %d\n\n", INT_MIN,INT_MAX);
    printf("The minimum value of long is %ld\nThe maximum value of long is %ld\n\n", LONG_MIN,LONG_MAX);
    printf("The minimum value of long long is %lld\nThe maximum value of long long is %lld\n\n", LLONG_MIN, LLONG_MAX);

    // This portion of code demonstrates some constants from float.h
    printf("Number of bits in float significand is %d\n", FLT_MANT_DIG);
    printf("Minimum number of significant decimal digits for a float is %d\n", FLT_DIG);
    printf("Minimum base-10 negative exponent for a float with a full set of significant figures is %d\n", FLT_MIN_10_EXP);
    printf("Maximum base-10 positive exponent for a float is %d\n", FLT_MAX_10_EXP);
    printf("Minimum value for a positive float retaining full precision is %d\n", FLT_MIN);
    printf("Maximum value for a positive float is %d\n\n", FLT_MAX);

    // There is one example that shows overflow with integer value
    printf("Integer overflow: %d\n", INT_MAX+1);
    return 0;
}
