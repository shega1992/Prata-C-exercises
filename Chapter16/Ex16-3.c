#include <stdio.h>
#include <math.h>
#define PI 3.14159265

typedef struct polar_v{
    double magnitude;
    double angle;
} POLAR_V;

typedef struct rect_v{
    double x;
    double y;
} RECT_V;

RECT_V convert_polar_to_rect(POLAR_V pv);

int main(void)
{
    POLAR_V input;
    RECT_V result;

    printf("Please enter the magnitude and the counterclockwise angle(non - numeric value(s) for exit): ");

    while(scanf("%lf %lf", &input.magnitude, &input.angle) == 2)
    {
        result = convert_polar_to_rect(input);
        printf("x = %f, y = %f\n", result.x, result.y);

        printf("Please enter next magnitude and next counterclockwise angle(non - numeric value(s) for exit): ");
    }
    return 0;
}

RECT_V convert_polar_to_rect(POLAR_V pv)
{
    RECT_V rv;

    rv.x = pv.magnitude * cos((pv.angle * PI) / 180);
    rv.y = pv.magnitude * sin((pv.angle * PI) / 180);

    return rv;
}
