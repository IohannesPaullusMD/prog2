#include <stdio.h>
#include <string.h>
#include "student_management_system.h"

#define ALL_PROGRAMS ""
#define STR_EQL 0
#define NULL_STUD (Student){"", "", '\0', {0,0,0,0,0}}

void inputStudent(Student *s)
{
    printf("ENTER STUDENT DATA\n");

    printf("NAME: ");
    scanf("%s", &s->name);

    printf("PROGRAM: ");
    scanf("%s", &s->program);    

    printf("SEX (M/F): ");
    scanf(" %c", &s->sex);

    printf("ENTER STUDENT GRADES\n");
    for (int i = 0; i < GRADES_LEN; ++i)
    {
        printf("GRADE %d: ", i+1);
        scanf(" %f", &s->grades[i]);
    }
}

void displayStudents(const Student studs[], const int COUNT)
{
    printf("\n%-50s | %-10s | SEX | GRADES\n", "NAME", "PROGRAM");

    for (int i = 0; i < COUNT; ++i)
    {
        printf
        (
            "%-50s | %-10s |  %c  | ",
            studs[i].name,
            studs[i].program,
            studs[i].sex
        );
        
        for (int j = 0; j < GRADES_LEN; ++j)
        {
            printf
            (
                "%.2f%s", 
                studs[i].grades[j], 
                (j+1 < GRADES_LEN ? ", " : " ")
            );
        }

        printf("(%.2f)", computeStudentAverage(studs[i]));
        printf("\n");
    }

}

float computeStudentAverage(Student s)
{
    float sum = 0;
    for (int i = 0; i < GRADES_LEN; ++i)
    {
        sum += s.grades[i];
    }

    return sum / GRADES_LEN;
}

Student getStudentWithHighestAverage(const Student studs[], const int COUNT)
{
    return getStudentWithHighestAverageInProgram(studs, COUNT, ALL_PROGRAMS);
}

Student getStudentWithHighestAverageInProgram(const Student studs[], const int COUNT, String program)
{
    int topStudIndex = -1;
    float maxAve = -1;
    float currAve;

    for (int i = 0; i < COUNT; ++i)
    {
        if 
        (
            program != ALL_PROGRAMS
            && strcmp(studs[i].program, program) != STR_EQL
        )
        {
            continue;
        }

        currAve = computeStudentAverage(studs[i]);
        if (currAve > maxAve)
        {
            topStudIndex = i;
            maxAve = currAve;
        }
    }

    return (COUNT > 0) ? studs[topStudIndex] : NULL_STUD;
}

Student getStudentByName(const Student studs[], const int COUNT, String searchKey)
{
    for (int i = 0; i < COUNT; ++i)
    {
        if (strcmp(studs[i].name, searchKey) == STR_EQL)
        {
            return studs[i];
        }
    }

    return NULL_STUD;
}

Student getStudentWithHighestGrade(const Student studs[], const int COUNT)
{
    int topStudIndex = -1;
    float maxGrade = -1;
    float currStudMaxGrade = -1;
    float currStudCurrGrade = -1;

    for (int i = 0; i < COUNT; ++i)
    {
        currStudMaxGrade = studs[i].grades[0];

        for (int j = 1; j < GRADES_LEN; ++j)
        {
            currStudCurrGrade = studs[i].grades[j];

            if (currStudCurrGrade > currStudMaxGrade)
            {
                currStudMaxGrade = currStudCurrGrade;
            }
        }

        if (currStudMaxGrade > maxGrade)
        {
            topStudIndex = i;
            maxGrade = currStudMaxGrade;
        }
    }

    return (COUNT > 0) ? studs[topStudIndex] : NULL_STUD;
}
