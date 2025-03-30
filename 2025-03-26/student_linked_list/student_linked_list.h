#ifndef STUD_LINKED_LIST
#define STUD_LINKED_LIST

#include <stdbool.h> 

#include "../student/student.h"

typedef struct Node
{
    Student val;
    struct Node *next;
}
StudentNode, *StudentLinkedList;

StudentLinkedList createStudentLinkedList();

/**
 * insert sorted based on birth date
 */
bool insertSortedStudentLinkedList
(
    StudentLinkedList *list,
    Student student
);

/**
 * ID | Name | Birth Day | Program & Year
 */
void displayStudentLinkedList(StudentLinkedList list);

#endif
