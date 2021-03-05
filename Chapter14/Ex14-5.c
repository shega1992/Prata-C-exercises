#include <stdio.h>
#define SIZE 20
#define CSIZE 4

struct name{
   char first_name[SIZE];
   char last_name[SIZE];
};

struct student{
    struct name person;
    float grade[3];
    float average;
};

void average_for_student(struct student people[], int n);
void print_info_about_each_struct(struct student people[], int n);
void calculate_and_print_avearge_for_course(struct student people[], int n);

int main(void)
{
    struct student people[CSIZE];

    for(int i = 0; i < CSIZE; i++)
    {
        printf("Please enter first name and last name of %d student: ", i+1);
        scanf("%19s %19s", people[i].person.first_name, people[i].person.last_name);
    }

    for(int i = 0; i < CSIZE; i++)
    {
        printf("Please enter 3 scores for %s %s: ", people[i].person.first_name, people[i].person.last_name);
        for(int j = 0; j < 3; j++)
            scanf("%f", &people[i].grade[j]);
    }

    average_for_student(people, CSIZE);
    print_info_about_each_struct(people, CSIZE);
    calculate_and_print_avearge_for_course(people, CSIZE);

    return 0;
}

void average_for_student(struct student people[], int n)
{
    float sum;

    for(int i = 0; i < n; i++)
    {
        sum = 0;
        for(int j = 0; j < 3; j++)
            sum += people[i].grade[j];

        people[i].average = sum / 3;
    }

}

void print_info_about_each_struct(struct student people[], int n)
{
    for(int i = 0; i < n; i++)
    {
        puts("*************************************************");
        printf("First name: %s\nLast name: %s\n", people[i].person.first_name, people[i].person.last_name);
        for(int j = 0; j < 3; j++)
           printf("Score for %d course: %f\n", j + 1, people[i].grade[j]);

        printf("Average score: %f\n", people[i].average);
        puts("*************************************************");
    }
}

void calculate_and_print_avearge_for_course(struct student people[], int n)
{
    float sum;

    for(int j = 0; j < 3; j++)
    {
        sum = 0;
        for(int i = 0; i < n; i++)
            sum += people[i].grade[j];
        printf("Average for %d course: %f\n", j+1, sum / n);
    }
}
