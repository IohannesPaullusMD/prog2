#include <stdio.h>
#include <stdlib.h>

#include "student_linked_list.h"

StudentNode* createNode(Student student)
{
    StudentNode* instance = calloc(1, sizeof(StudentNode));
    if (instance == NULL) { return NULL; }

    instance->val = student;
    instance->next = NULL;

    return instance;
}

StudentLinkedList createStudentLinkedList()
{
    return NULL; // Initialize empty linked list (head is NULL)
}

bool insertSortedStudentLinkedList(StudentLinkedList* list, Student student)
{
    if (list == NULL) { return false; }
    ///*
    StudentNode** head = (StudentNode**)list;
    
    if (*head == NULL) 
    {
        *head = createNode(student);
        return *head != NULL;
    }

    StudentNode* prev = NULL;
    StudentNode* curr = *head;

    while (curr != NULL && compareDates(curr->val.birthDate, student.birthDate) <= 0)
    {
        prev = curr;
        curr = curr->next;
    }

    StudentNode* newNode = createNode(student);
    if (newNode == NULL) { return false; }

    if (prev == NULL)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        newNode->next = curr;
        prev->next = newNode;
    }
    //*/

//    StudentNode *newNode = createNode(student);
//    if (newNode == NULL) { return false; }



    return true;
}

void displayStudentLinkedList(StudentLinkedList list)
{
    StudentNode* curr = list;
    printf("ID, Name, Birth Day, Program & Year\n");
    
    while (curr != NULL)
    {
        printf("%03d, ", curr->val.id);
        displayName(curr->val.name);
        printf(", ");
        displayDate(curr->val.birthDate);
        printf
        (
            ", %s %d\n",
            curr->val.program,
            curr->val.level
        );
        curr = curr->next;
    }
}
