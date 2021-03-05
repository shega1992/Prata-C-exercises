#include <stdio.h>
#include <stdbool.h>
#define ON 1
#define OFF 0
#define SWITCH 1
#define ALIGNMENT_LEFT 0
#define ALIGNMENT_CENTER 1
#define ALIGNMENT_RIGHT 2
// MASKS
#define MASK_FONT_ID 0x000000FF
#define MASK_FONT_SIZE 0x00007F00
#define MASK_FONT_ALIGNMENT 0x00030000
#define MASK_FONT_BOLD 0x00040000
#define MASK_FONT_ITALIC 0x00080000
#define MASK_FONT_UNDERLINE 0x00100000

typedef struct {
    unsigned int font_ID      : 8;
    unsigned int font_size    : 7;
    unsigned int              : 1;
    unsigned int alignment    : 2;
    bool bold                 : 1;
    bool italic               : 1;
    bool underline            : 1;
}FONT;

union Views {
  FONT font;
  unsigned long ul_long;
};

void show_menu(unsigned long ul);
unsigned long change_font_ID(unsigned long ul);
unsigned long change_font_size(unsigned long ul);
unsigned long change_alignment(unsigned long ul);
unsigned long change_bold(unsigned long ul);
unsigned long change_italic(unsigned long ul);
unsigned long change_underline(unsigned long ul);
void eatline(void);

int main(void)
{
    union Views box = {{1, 12, ALIGNMENT_LEFT, OFF, OFF, OFF}};
    char selection;

    show_menu(box.ul_long);

    while(scanf("%c", &selection) && selection != 'q')
    {
        switch(selection)
        {
            case 'f':
                box.ul_long = change_font_ID(box.ul_long);
                break;
            case 's':
                box.ul_long = change_font_size(box.ul_long);
                break;
            case 'a':
                box.ul_long = change_alignment(box.ul_long);
                break;
            case 'b':
                box.ul_long = change_bold(box.ul_long);
                break;
            case 'i':
                box.ul_long = change_italic(box.ul_long);
                break;
            case 'u':
                box.ul_long = change_underline(box.ul_long);
                break;
            default:
                printf("You've entered incorrect option\n"
                       "Please select the option from menu\n\n");
                break;
        }

        eatline();
        show_menu(box.ul_long);
    }

    return 0;
}

void show_menu(unsigned long ul)
{
    printf("ID\t" "SIZE\t" "ALIGNMENT\t" " B\t" " I\t" " U\n");

    printf("%Lu\t", ul & MASK_FONT_ID);
    printf("%3Lu\t", (ul & MASK_FONT_SIZE) >> 8);

    switch((ul & MASK_FONT_ALIGNMENT) >> 16)
    {
        case ALIGNMENT_LEFT:
            printf("%6s\t\t", "left");
            break;
        case ALIGNMENT_CENTER:
            printf("%6s\t\t", "center");
            break;
        case ALIGNMENT_RIGHT:
            printf("%6s\t\t", "right");
            break;
    }

    (((ul & MASK_FONT_BOLD) >> 18) == ON)? printf("on\t") : printf("off\t");
    (((ul & MASK_FONT_ITALIC) >> 19) == ON)? printf("on\t") : printf("off\t");
    (((ul & MASK_FONT_UNDERLINE) >> 20) == ON)? printf("on\n\n") : printf("off\n\n");

    printf("f)change font\t" "s)change size\t" "a)change alignment\n"
           "b)toggle bold\t" "i)toggle italic\t" "u)toggle underline\n"
           "q)quit\n");
}

unsigned long change_font_ID(unsigned long ul)
{
    unsigned long value;

    fputs("Enter font ID (0 - 255): ", stdout);

    while(scanf("%lu", &value) != 1 || value > 255)
    {
        printf("You've entered incorrect value for font ID\n"
               "Please enter the value from 0 to 255: ");

        eatline(); // discard the input
    }

    ul &= (~MASK_FONT_ID);

    return ul | value;
}

unsigned long change_font_size(unsigned long ul)
{
    unsigned long value;

    fputs("Enter font size (0 - 127): ", stdout);

    while(scanf("%lu", &value) != 1 || value > 127)
    {
        printf("You've entered incorrect value for font size\n"
               "Please enter the value from 0 to 127: ");

        eatline(); // discard the input
    }

    ul &= (~MASK_FONT_SIZE);

    return ul | (value << 8);
}

unsigned long change_alignment(unsigned long ul)
{
    char selection;
    eatline();

    printf("Select alignment:\n"
    "l)left\t" "c)center\t" "r)right\n");

    scanf("%c", &selection);

    switch(selection)
    {
        case 'l':
            ul &= (~MASK_FONT_ALIGNMENT);
            ul |= (ALIGNMENT_LEFT << 16);
            break;
        case 'c':
            ul &= (~MASK_FONT_ALIGNMENT);
            ul |= (ALIGNMENT_CENTER << 16);
            break;
        case 'r':
            ul &= (~MASK_FONT_ALIGNMENT);
            ul |= (ALIGNMENT_RIGHT << 16);
            break;
        default:
            printf("You've selected incorrect option\n"
                   "Alignment hasn't been changed\n\n");
            break;
    }

    return ul;
}

unsigned long change_bold(unsigned long ul)
{
    if((ul & MASK_FONT_BOLD) != MASK_FONT_BOLD)
        return ul ^ (SWITCH << 18);
    else
        return ul ^ (SWITCH << 18);
}

unsigned long change_italic(unsigned long ul)
{
    if((ul & MASK_FONT_ITALIC) != MASK_FONT_ITALIC)
        return ul ^ (SWITCH << 19);
    else
        return ul ^ (SWITCH << 19);
}

unsigned long change_underline(unsigned long ul)
{
    if((ul & MASK_FONT_UNDERLINE) != MASK_FONT_UNDERLINE)
        return ul ^ (SWITCH << 20);
    else
        return ul ^ (SWITCH << 20);
}

void eatline(void)
{
    while(getchar() != '\n')
        continue;
}
