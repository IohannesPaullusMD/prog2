#ifndef STUD_LINKED_LIST
#define STUD_LINKED_LIST

#include <stdbool.h> 

#include "../student/student.h"

typedef struct
{
    Student val;
    Node next;
}
_Node, *Node;

typedef struct 
{
    Node head;
    Node tail;
}
_StudentLinkedList, *StudentLinkedList;

Node newNode(Student student);

StudentLinkedList newStudentArrayList(int initCapacity);

/**
 * insert sorted based on birth date
 */
bool insertSortedStudentLinkedList
(
    StudentLinkedList list,
    Student student
);

/**
 * ID | Name | Birth Day | Program & Year
 */
void displayStudentArrayList(StudentLinkedList list);

#endif
