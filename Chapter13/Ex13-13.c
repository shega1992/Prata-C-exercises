#include <stdio.h>
#include <stdlib.h>

void size_of_array_is_correct(int *rows, int *cols);
void fill_array_of_int(int rows, int cols, int arr[rows][cols], FILE *fp);
void convert_array_of_int_to_char(int rows, int cols, int cols_ch, int arr_of_int[rows][cols], char arr_of_ch[rows][cols_ch]);
void print_array_of_ch(int rows, int cols_ch, char arr[rows][cols_ch]);
void write_array_of_ch_into_text_file(int rows, int cols_ch, char arr[rows][cols_ch], FILE *fp);

int main(int argc, char *argv[])
{
    FILE *fp;
    int rows, cols, cols_ch;

    fputs("Please enter the number of rows: ", stdout);
    scanf("%d", &rows);
    fputs("Please enter the number of columns: ", stdout);
    scanf("%d", &cols);

    size_of_array_is_correct(&rows, &cols);

    cols_ch = cols + 1;

    int arr_of_int[rows][cols];
    char arr_of_ch[rows][cols_ch];

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

    fill_array_of_int(rows, cols, arr_of_int, fp);

    if(fclose(fp) != 0)
        fprintf(stderr, "Error in closing file %s", argv[1]);

    convert_array_of_int_to_char(rows, cols, cols_ch, arr_of_int, arr_of_ch);
    print_array_of_ch(rows, cols_ch, arr_of_ch);
    write_array_of_ch_into_text_file(rows, cols_ch, arr_of_ch, fp);

    return 0;
}

void size_of_array_is_correct(int *rows, int *cols)
{
    while(*rows < 1 || *rows > 20)
    {
        printf("You've entered incorrect value for rows\n"
               "Please enter the value from 1 to 20: ");
        scanf("%d", rows);
    }

    while(*cols < 1 || *cols > 30)
    {
        printf("You've entered incorrect value for columns\n"
               "Please enter the value from 1 to 30: ");
        scanf("%d", cols);
    }
}

void fill_array_of_int(int rows, int cols, int arr[rows][cols], FILE *fp)
{
    int i,j,ch;

    for(i = 0; i < rows; i++)
    {
        for(j = 0; j < cols; j++)
            fscanf(fp, "%d", &arr[i][j]);

        while((ch = getc(fp)) != '\n') // discard the rest of the line
        {
            if(ch == EOF)
                break;
            else
                continue;
        }

    }


}

void convert_array_of_int_to_char(int rows, int cols, int cols_ch, int arr_of_int[rows][cols], char arr_of_ch[rows][cols_ch])
{
    int i,j;

    for(i = 0; i < rows; i++)
    {
       for(j = 0; j < cols; j++)
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


void print_array_of_ch(int rows, int cols_ch, char arr[rows][cols_ch])
{
    int i;

    for(i = 0; i < rows; i++)
        printf("%s\n", arr[i]);
}

void write_array_of_ch_into_text_file(int rows, int cols_ch, char arr[rows][cols_ch], FILE *fp)
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
