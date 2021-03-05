#include <stdio.h>
#include <stdlib.h>
#define ROWS 20
#define COLS_OF_INT_ARR 30
#define COLS_OF_CH_ARR 31

void fill_array_of_int(int arr[][COLS_OF_INT_ARR], int rows, FILE *fp);
void convert_array_of_int_to_char(int arr_of_int[][COLS_OF_INT_ARR], char arr_of_ch[][COLS_OF_CH_ARR], int rows);
void print_array_of_ch(char arr[][COLS_OF_CH_ARR], int rows);
void write_array_of_ch_into_text_file(char arr[][COLS_OF_CH_ARR], int rows, FILE *fp);

int main(int argc, char *argv[])
{
    FILE *fp;
    int arr_of_int[ROWS][COLS_OF_INT_ARR];
    char arr_of_ch[ROWS][COLS_OF_CH_ARR];

    if(argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if((fp = fopen(argv[1], "r")) == NULL)
    {
        printf("Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    fill_array_of_int(arr_of_int, ROWS, fp);

    if(fclose(fp) != 0)
        fprintf(stderr, "Error in closing file %s", argv[1]);

    convert_array_of_int_to_char(arr_of_int, arr_of_ch, ROWS);
    print_array_of_ch(arr_of_ch, ROWS);
    write_array_of_ch_into_text_file(arr_of_ch, ROWS, fp);

    return 0;
}

void fill_array_of_int(int arr[][COLS_OF_INT_ARR], int rows, FILE *fp)
{
    int i,j;

    for(i = 0; i < rows; i++)
        for(j = 0; j < COLS_OF_INT_ARR; j++)
            fscanf(fp, "%d", &arr[i][j]);
}

void convert_array_of_int_to_char(int arr_of_int[][COLS_OF_INT_ARR], char arr_of_ch[][COLS_OF_CH_ARR], int rows)
{
    int i,j;

    for(i = 0; i < rows; i++)
    {
       for(j = 0; j < COLS_OF_INT_ARR; j++)
            switch(arr_of_int[i][j])
        {
            case 0:
                arr_of_ch[i][j] = ' ';
                break;
            case 1:
                arr_of_ch[i][j] = '.';
                break;
            case 2:
                arr_of_ch[i][j] = '\'';
                break;
            case 3:
                arr_of_ch[i][j] = ':';
                break;
            case 4:
                arr_of_ch[i][j] = '~';
                break;
            case 5:
                arr_of_ch[i][j] = '*';
                break;
            case 6:
                arr_of_ch[i][j] = '=';
                break;
            case 7:
                arr_of_ch[i][j] = '$';
                break;
            case 8:
                arr_of_ch[i][j] = '%';
                break;
            case 9:
                arr_of_ch[i][j] = '#';
                break;
        }

        arr_of_ch[i][j] = '\0';
    }


}


void print_array_of_ch(char arr[][COLS_OF_CH_ARR], int rows)
{
    int i;

    for(i = 0; i < rows; i++)
        printf("%s\n", arr[i]);
}

void write_array_of_ch_into_text_file(char arr[][COLS_OF_CH_ARR], int rows, FILE *fp)
{
   if((fp = fopen("Out.txt", "w")) == NULL)
    {
        printf("Can't create or open \"Out\".\n");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < rows; i++)
        fprintf(fp, "%s\n", arr[i]);

    if(fclose(fp) != 0)
        fprintf(stderr, "Error in closing file \"Out\".\n");
}
