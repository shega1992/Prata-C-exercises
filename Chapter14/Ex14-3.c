/* manybook.c -- multiple book inventory */
#include <stdio.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100 /* maximum number of books */

char * s_gets(char * st, int n);

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

void sort_in_alphabet_order(struct book library[], int count);
void sort_by_price(struct book library[], int count);

int main(void)
{
    struct book library[MAXBKS]; /* array of book structures */
    int count = 0;
    int index;
    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
           && library[count].title[0] != '\0')
    {
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue; /* clear input line */
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }

    if (count > 0)
    {
        printf("Here is the list of your books:\n");
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title,
                    library[index].author, library[index].value);

        sort_in_alphabet_order(library, count);
        sort_by_price(library, count);
    }
    else
        printf("No books? Too bad.\n");

    return 0;

}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // look for newline
        if (find) // if the address is not NULL,
            *find = '\0'; // place a null character there
        else
            while (getchar() != '\n')
                continue; // dispose of rest of line
    }

    return ret_val;
}

void sort_in_alphabet_order(struct book library[], int count)
{
    int i,j;
    struct book temp;
    struct book sort_library[count];

    for(i = 0; i < count; i++)
        sort_library[i] = library[i];

    for(i = 0; i < count - 1; i++)
        for(j = i+1; j < count; j++)
            if(strcmp(sort_library[i].title, sort_library[j].title) > 0)
            {
                temp = sort_library[i];
                sort_library[i] = sort_library[j];
                sort_library[j] = temp;
            }
    puts("**************************************************");
    printf("Here is the list of your books in alphabet order:\n");
    for (i = 0; i < count; i++)
            printf("%s by %s: $%.2f\n", sort_library[i].title,
                    sort_library[i].author, sort_library[i].value);
}

void sort_by_price(struct book library[], int count)
{
   int i,j;
   struct book temp;
   struct book sort_library[count];

   for(i = 0; i < count; i++)
        sort_library[i] = library[i];

    for(i = 0; i < count - 1; i++)
        for(j = i+1; j < count; j++)
            if(sort_library[i].value > sort_library[j].value)
            {
                temp = sort_library[i];
                sort_library[i] = sort_library[j];
                sort_library[j] = temp;
            }
    puts("**************************************************");
    printf("Here is the list of your books sorted by price:\n");
    for (i = 0; i < count; i++)
            printf("%s by %s: $%.2f\n", sort_library[i].title,
                    sort_library[i].author, sort_library[i].value);

}
