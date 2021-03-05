#include <stdio.h>
#include <ctype.h>

int get_first();

int main(void)
{
    printf("Your input: ");
    printf("The first non - whitespace character: %c", get_first());

    return 0;
}

int get_first()
{
    int character;

    while((character = getchar()))
        if(!isspace(character))
            return character;

}
