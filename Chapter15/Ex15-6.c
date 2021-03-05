#include <stdio.h>
#include <stdbool.h>
#define ON 1
#define OFF 0
#define ALIGNMENT_LEFT 0
#define ALIGNMENT_CENTER 1
#define ALIGNMENT_RIGHT 2

typedef struct {
    unsigned int font_ID      : 8;
    unsigned int font_size    : 7;
    unsigned int              : 1;
    unsigned int alignment    : 2;
    bool bold                 : 1;
    bool italic               : 1;
    bool underline            : 1;
}FONT;

void show_menu(FONT *font);
unsigned int change_font_ID(unsigned int value);
unsigned int change_font_size(unsigned int value);
unsigned int change_alignment(unsigned int value);
bool change_bold(bool value);
bool change_italic(bool value);
bool change_underline(bool value);
void eatline(void);

int main(void)
{
    FONT font = {1, 12, ALIGNMENT_LEFT, OFF, OFF, OFF};
    char selection;

    show_menu(&font);

    while(scanf("%c", &selection) && selection != 'q')
    {
        switch(selection)
        {
            case 'f':
                font.font_ID = change_font_ID(font.font_ID);
                break;
            case 's':
                font.font_size = change_font_size(font.font_size);
                break;
            case 'a':
                font.alignment = change_alignment(font.alignment);
                break;
            case 'b':
                font.bold = change_bold(font.bold);
                break;
            case 'i':
                font.italic = change_italic(font.italic);
                break;
            case 'u':
                font.underline = change_underline(font.underline);
                break;
            default:
                printf("You've entered incorrect option\n"
                       "Please select the option from menu\n\n");
                break;
        }

        eatline();
        show_menu(&font);
    }

    return 0;
}

void show_menu(FONT *font)
{
    printf("ID\t" "SIZE\t" "ALIGNMENT\t" " B\t" " I\t" " U\n");

    printf("%u\t", font->font_ID);
    printf("%3u\t", font->font_size);

    switch(font->alignment)
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

    (font->bold == ON)? printf("on\t") : printf("off\t");
    (font->italic == ON)? printf("on\t") : printf("off\t");
    (font->underline == ON)? printf("on\n\n") : printf("off\n\n");

    printf("f)change font\t" "s)change size\t" "a)change alignment\n"
           "b)toggle bold\t" "i)toggle italic\t" "u)toggle underline\n"
           "q)quit\n");
}

unsigned int change_font_ID(unsigned int value)
{
    fputs("Enter font ID (0 - 255): ", stdout);

    while(scanf("%u", &value) != 1 || value > 255)
    {
        printf("You've entered incorrect value for font ID\n"
               "Please enter the value from 0 to 255: ");

        eatline(); // discard the input
    }

    return value;
}

unsigned int change_font_size(unsigned int value)
{
    fputs("Enter font size (0 - 127): ", stdout);

    while(scanf("%u", &value) != 1 || value > 127)
    {
        printf("You've entered incorrect value for font size\n"
               "Please enter the value from 0 to 127: ");

        eatline(); // discard the input
    }

    return value;
}

unsigned int change_alignment(unsigned int value)
{
    char selection;
    eatline();

    printf("Select alignment:\n"
    "l)left\t" "c)center\t" "r)right\n");

    scanf("%c", &selection);

    switch(selection)
    {
        case 'l':
            value = ALIGNMENT_LEFT;
            break;
        case 'c':
            value = ALIGNMENT_CENTER;
            break;
        case 'r':
            value = ALIGNMENT_RIGHT;
            break;
        default:
            printf("You've selected incorrect option\n"
                   "Alignment hasn't been changed\n\n");
            break;
    }

    return value;
}

bool change_bold(bool value)
{
    if(value == OFF)
        return ON;
    else
        return OFF;
}

bool change_italic(bool value)
{
    if(value == OFF)
        return ON;
    else
        return OFF;
}

bool change_underline(bool value)
{
    if(value == OFF)
        return ON;
    else
        return OFF;
}

void eatline(void)
{
    while(getchar() != '\n')
        continue;
}
