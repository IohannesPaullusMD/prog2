#ifndef STUD_H
#define STUD_H

#include "../name/name.h"
#include "../date/date.h"
#include "../string/my_string.h"

typedef struct 
{
    int id;
    Name name;
    Date birthDate;
    String program;
    int level;
}
Student;

Student createStudent
(
    int id,
    Name name,
    Date birthDate,
    String program,
    int level
);

/**
 * ID: xxx
 * Name: xxx
 * Birth Date: xxx
 * Program & Year: xxx - xx
 */
void displayStudent(Student student);

#endif
