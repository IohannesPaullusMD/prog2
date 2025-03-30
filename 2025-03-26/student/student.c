#include <stdio.h>
#include <stdlib.h>

#include "student.h"

Student newStudent
(
    int id,
    Name name,
    Date birthDate,
    String program,
    int level
)
{
    Student instance = calloc(1, sizeof(_Student));
    if (instance == NULL) { return NULL; }

    instance->id = id;
    instance->name = name;
    instance->birthDate = birthDate;
    strcpy(&instance->program, program);
    instance->level = level;

    return instance;
}

/**
 * ID: xxx
 * Name: xxx
 * Birth Date: xxx
 * Program & Year: xxx - xx
 */
void displayStudent(Student student)
{
    printf("ID: %03d\nName: ", student->id);
    displayName(student->name);
    printf("\nBirth Date: ");
    displayDate(student->birthDate);
    printf
    (
        "\nProgram & Year: %s - %02d\n",
        student->program, 
        student->program
    );
}
