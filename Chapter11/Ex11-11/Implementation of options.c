#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "header.h"

void print_the_list_of_strings(char st[][NUMBER_OF_CHARACTERS_IN_STRING], int rows)
{
    int i;

    for(i = 0; i < rows; i++)
        printf("%s\n", st[i]);
}

void sort_the_strings_in_ASCII_collating_sequence(char *st[], int rows)
{
    int top,seek,k;
    char *temp;

    for(top = 0; top < rows - 1; top++)
        for(seek = top + 1; seek < rows; seek++)
            if(strcmp(st[top], st[seek]) > 0)
            {
                temp = st[top];
                st[top] = st[seek];
                st[seek] = temp;
            }

    for(k = 0; k < rows; k++)
        puts(st[k]);

}

void sort_the_strings_in_order_of_increasing_length(char *st[], int rows)
{
    int top,seek,k;
    char *temp;

    for(top = 0; top < rows - 1; top++)
        for(seek = top + 1; seek < rows; seek++)
            if(strlen(st[top]) > strlen(st[seek]))
            {
                temp = st[top];
                st[top] = st[seek];
                st[seek] = temp;
            }

    for(k = 0; k < rows; k++)
        puts(st[k]);
}

void sort_the_strings_in_order_of_the_length_of_the_first_word_in_the_string(char *st[], int rows)
{
    int top,seek,k;
    char *temp;
    /* Next two variables will point to first whitespace or punctuation character
    except for cases when the first character(s) in string is(are) whitespace or punctuation */
    char *blank_in_top;
    char *blank_in_seek;


    for(top = 0; top < rows - 1; top++)
        for(seek = top + 1; seek < rows; seek++)
        {
            blank_in_top = find_first_whitespace_or_punctuation_character(st[top]);
            blank_in_seek = find_first_whitespace_or_punctuation_character(st[seek]);

            if(blank_in_top - st[top] > blank_in_seek - st[seek])
            {
                temp = st[top];
                st[top] = st[seek];
                st[seek] = temp;
            }
        }

    for(k = 0; k < rows; k++)
        puts(st[k]);

}

char *find_first_whitespace_or_punctuation_character(char *st)
{
    int first_char_are_not_alnum = 0;

    while(ispunct(*st) || isspace(*st))// handle the input if the first characters are not a letter or digit
    {
       first_char_are_not_alnum++;
       st++;
    }


    while(isalnum(*st))
        st++;


    return st - first_char_are_not_alnum;
}
