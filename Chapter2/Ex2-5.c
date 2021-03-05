#include <stdio.h>

void br(void);
void ic(void);

int main(void)
{
    br();
    ic();

    printf("India, China,\nBrazil, Russia\n");

    return 0;
}

void br(void)
{
    printf("Brazil, Russia,");
}

void ic(void)
{
   printf("India, China\n");
}
