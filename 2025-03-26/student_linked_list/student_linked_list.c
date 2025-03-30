#include <stdio.h>
#include <stdlib.h>

#include "student_linked_list.h"

Node newNode(Student student)
{
    Node instance = calloc(1, sizeof(_Node));
    if (instance == NULL) { return NULL; }

    instance->val = student;

    return instance;
}

StudentLinkedList newStudentArrayList(int initCapacity)
{
    StudentLinkedList instance = calloc(1, sizeof(_StudentLinkedList));
    return instance;
}

bool insertSortedStudentLinkedList(StudentLinkedList list, Student student)
{
    if (list == NULL) { return false; }
    if (list->head == NULL) 
    {
        list->head = newNode(student);
        return true;
    }

    Node prev = NULL;
    Node curr = list->head;

    while (curr != NULL && compareDates(curr->val->birthDate, student->birthDate) < 0)
    {
        prev = curr;
        curr = curr->next;
    }

    Node _newNode = newNode(student);
    if (_newNode == NULL) { return false; }

    if (prev == NULL)
    {
        _newNode->next = list->head;
        list->head = _newNode;
    }
    else
    {
        _newNode->next = curr;
        prev->next = _newNode;
    }

    return true;
}


void displayStudentArrayList(StudentLinkedList list)
{
    Node curr = list->head;
    printf("ID  |Name%26s |Birth Day   |Program & Year\n", "");
    
    while (curr != NULL)
    {
        printf("%03d |", curr->val->id);
        displayName(curr->val->name);
        printf(" |");
        displayDate(curr->val->birthDate);
        printf
        (
            " |%s %d\n",
            curr->val->program,
            curr->val->level
        );
        curr = curr->next;
    }
}
