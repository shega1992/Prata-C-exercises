#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 15
#define NLEN 40

struct names{
    char first_name[NLEN];
    char last_name[NLEN];
};

void show_array(const struct names staff[], int n);
int comp(const void * p1, const void * p2);

int main(void)
{
    struct names staff[SIZE] = {
        {"Amy", "Poehler"},
		{"Phyllis", "Smith"},
		{"Richard", "Kind"},
		{"Bill", "Hader"},
		{"Lewis", "Black"},
		{"Mindy", "Kaling"},
		{"Kaitlyn", "Dias"},
		{"Diane", "Lane"},
		{"Kyle", "MacLachlan"},
		{"Paula", "Poundstone"},
		{"Bobby", "Moynihan"},
		{"Paula", "Pell"},
		{"Frank", "Oz"},
		{"Dave", "Oz"},
		{"Josh", "Cooley"},
	};
    puts("Original array: ");
	show_array(staff, SIZE);

	qsort(staff, SIZE, sizeof(struct names), comp);

	puts("********************");
	puts("Array after qsort: ");
	show_array(staff, SIZE);

    return 0;
}

void show_array(const struct names staff[], int n)
{
    int i;

    for(i = 0; i < n; i++)
        printf("%s %s\n", staff[i].last_name, staff[i].first_name);
}

int comp(const void * p1, const void * p2)
{
    const struct names *ps1 = (const struct names *) p1;
    const struct names *ps2 = (const struct names *) p2;
    int res;

    res = strcmp(ps1->last_name, ps2->last_name); /* compare last names */
    if (res != 0)
        return res;
    else /* last names identical, so compare first names */
        return strcmp(ps1->first_name, ps2->first_name);
}
