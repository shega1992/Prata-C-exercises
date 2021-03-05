#include <stdio.h>
#include <ctype.h>

int character_is_a_letter(int characters);

int main(void)
{
    int characters;

    printf("Your input(Ctrl + z for exit): ");

    while((characters = getchar()) != EOF)
    {
        printf("%d\n", character_is_a_letter(characters));
    }

    return 0;
}

int character_is_a_letter(int characters)
{
    if(isalpha(characters))
    {
        printf("%c is a letter. Numerical location in the alphabet: ", characters );
        return toupper(characters) - 64;
    }
    else
    {
        if(isspace(characters))
            printf("Whitespace character is not a letter. Return value: ");
        else
            printf("%c is not a letter. Return value: ", characters);
        return -1;
    }

}
