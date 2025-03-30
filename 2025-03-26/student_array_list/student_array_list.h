#ifndef STUD_ARR_LIST
#define STUD_ARR_LIST

#include <stdbool.h> 

#include "../student/student.h"

typedef struct 
{
    _Student *arr;
    int size;
    int capacity;
}
_StudentArrayList, *StudentArrayList;

StudentArrayList newStudentArrayList(int initCapacity);

/**
 * insert sorted based on last name
 */
bool insertSortedStudentArrayList
(
    StudentArrayList list,
    Student Student
);

/**
 * ID | Name | Birth Day | Program & Year
 */
void displayStudentArrayList(StudentArrayList list);

#endif
