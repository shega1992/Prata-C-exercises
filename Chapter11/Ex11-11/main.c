#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

int main(void)
{
    int i = 0;
    int selection;
    int string_count = 0;
    char string[NUMBER_OF_STRINGS][NUMBER_OF_CHARACTERS_IN_STRING];
    char *ptstr[NUMBER_OF_CHARACTERS_IN_STRING];

    while(i < NUMBER_OF_STRINGS && printf("Please enter %d string(Ctrl+z to finish the input): ", i) && s_gets(string[i], NUMBER_OF_CHARACTERS_IN_STRING))
    {
        ptstr[i] = string[i];
        string_count++;
        i++;
    }

    if(string_count < 1)
        printf("You have entered %d strings\n", string_count);
    else
       while((selection = menu()) != QUIT){
        switch(selection)
        {
            case 1:
                print_the_list_of_strings(string, string_count);
                break;
            case 2:
                sort_the_strings_in_ASCII_collating_sequence(ptstr, string_count);
                break;
            case 3:
                sort_the_strings_in_order_of_increasing_length(ptstr, string_count);
                break;
            case 4:
                sort_the_strings_in_order_of_the_length_of_the_first_word_in_the_string(ptstr, string_count);
                break;
            default:
                puts("Incorrect option. Please select option from 1 to 5");
                break;

        }
    }



    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    ret_val = fgets(st, n, stdin);
    if (ret_val) // i.e., ret_val != NULL
        {
            while (*st != '\n' && *st != '\0')
                st++;
            if (*st == '\n')
                *st = '\0';
            else // must have words[i] == '\0'
                while ( getchar() != '\n')
                    continue;
        }
    return ret_val;

}

int menu(void)
{
    int input;

    puts("******************************************************************************");
    printf("Please select the option:\n"
           "1.Print the original list of strings\n"
           "2.Print the strings in ASCII collating sequence\n"
           "3.Print the strings in order of increasing length\n"
           "4.Print the strings in order of the length of the first word in the string\n"
           "5.Quit\n");
    puts("******************************************************************************");
    scanf("%d", &input);

    return input;
}
