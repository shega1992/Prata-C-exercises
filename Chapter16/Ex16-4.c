#include <stdio.h>
#include <time.h>

void test(double time);

int main(void)
{
    double time;

    fputs("Enter desired time delay in seconds: ", stdout);

    while(scanf("%lf", &time) == 1)
    {
        puts("Starting.");
		test(time);
		printf("It is now %2f seconds later!\n", time);
		printf("Enter desired time delay in seconds: ");
    }


    return 0;
}

void test(double time)
{
    clock_t start, end;

    start = clock();

    while (((end = clock()) - start) /  (double) CLOCKS_PER_SEC < time)
		continue;

}
