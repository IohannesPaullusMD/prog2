#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"

Student createStudent
(
    int id,
    Name name,
    Date birthDate,
    String program,
    int level
)
{
    Student student;
    
    student.id = id;
    student.name = name;
    student.birthDate = birthDate;
    strcpy(student.program, program);
    student.level = level;
    
    return student;
}

/**
 * ID: xxx
 * Name: xxx
 * Birth Date: xxx
 * Program & Year: xxx - xx
 */
void displayStudent(Student student)
{
    printf("ID: %03d\nName: ", student.id);
    displayName(student.name);
    printf("\nBirth Date: ");
    displayDate(student.birthDate);
    printf
    (
        "\nProgram & Year: %s - %02d\n",
        student.program, 
        student.level
    );
}
