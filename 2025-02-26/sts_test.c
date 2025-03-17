#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "student_management_system.h"

#define STUD_LEN 5

void testComputeStudentAverage(Student s);

int main() {
    Student studs[STUD_LEN];
    Student student;
    int count;

    for (count = 0; count < STUD_LEN; ++count)
    {
        printf("\nStudent %d\n", count+1);
        inputStudent(&studs[count]);
    }

    displayStudents(studs, count);

    testComputeStudentAverage(studs[0]);
    testComputeStudentAverage(studs[1]);
    
    student = getStudentWithHighestAverage(studs, count);
    printf("StudentWithHighestAverage: %s\n", student.name);

    student = getStudentWithHighestAverageInProgram(studs, count, "IT");
    printf("getStudentWithHighestAverageInProgram: %s\n", student.name);

    student = getStudentByName(studs, count, studs[2].name);
    printf
    (
        "%s: %s\n",
        (memcmp(&student, &studs[2], sizeof(Student)) == 0)
            ? "student found"
            : "student not found",
        studs[2].name
    );

    student = getStudentByName(studs, count, "John Du");
    printf
    (
        "%s: %s\n",
        (memcmp(&student, "John Du", sizeof(Student)) == 0)
            ? "student found"
            : "student not found",
        "John Du"
    );

    student = getStudentWithHighestGrade(studs, count);
    printf("getStudentWithHighestGrade: %s\n", student.name);


    return 0;
}

void testComputeStudentAverage(Student s) {
    float avg = computeStudentAverage(s);
    printf("%s's Computed Average: %.2f\n", s.name, avg);
}

