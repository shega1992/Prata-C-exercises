#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int character;
    int i = 0;
    unsigned short int field_for_c_specifier = 2;
    unsigned short int field_for_d_specifier = 3;

    printf("Your input: ");

    while((character = getchar()) != EOF)
    {
            if(iscntrl(character))
                {
                    switch(character){
                        case '\n':
                            putchar('\n');
                            printf("\\n-%*d ", field_for_d_specifier, character);
                            i = -1;
                            break;
                        case '\t':
                            printf("\\t-%*d ", field_for_d_specifier, character);
                            break;
                        default:
                            printf("^%c-%*d ", character+64, field_for_d_specifier, character);
                            break;

                    }
                }
            else
                printf("%*c-%*d ",
                       field_for_c_specifier, character, field_for_d_specifier, character);

        if(++i % 10 == 0)
            putchar('\n');
    }

    return 0;
}
