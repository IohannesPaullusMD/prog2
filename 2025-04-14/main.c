#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "2025-03-26/student_linked_list/student_linked_list.h"
#include "2025-03-26/student_array_list/student_array_list.h"

StudentLinkedList getStudentsWithBirthMonth(StudentArrayList arrList, int month);
StudentLinkedList removeStudents(StudentLinkedList *list, String program, int year);

int main()
{
    Student student1 = createStudent(0, createName("John", "Iohann", "Doea"), createDate(1, 1, 2020), "Information Technology", 1);
    Student student2 = createStudent(1, createName("Jane", "Ina", "Doeb"), createDate(2, 1, 2000), "Computer Science", 2);
    Student student3 = createStudent(2, createName("Alice", "Ihanna", "Doec"), createDate(3, 3, 2005), "Information Science", 2);
    Student student4 = createStudent(3, createName("Bob", "Ioha", "Doed"), createDate(2, 1, 2000), "Information Science", 1);
    Student student5 = createStudent(4, createName("Charlie", "Inna", "Doee"), createDate(5, 5, 2000), "Computer Science", 2);
    
    StudentArrayList list = createStudentArrayList(5);
    insertSortedStudentArrayList(&list, student5);
    insertSortedStudentArrayList(&list, student4);
    insertSortedStudentArrayList(&list, student3);
    insertSortedStudentArrayList(&list, student2);
    insertSortedStudentArrayList(&list, student1);
    StudentLinkedList list3 = getStudentsWithBirthMonth(list, 3);
    displayStudentLinkedList(list3);
    
    printf("\n");

    StudentLinkedList list2 = createStudentLinkedList();
    insertSortedStudentLinkedList(&list2, student5);
    insertSortedStudentLinkedList(&list2, student1);
    insertSortedStudentLinkedList(&list2, student3);
    insertSortedStudentLinkedList(&list2, student2);
    insertSortedStudentLinkedList(&list2, student4);
    StudentLinkedList list4 = removeStudents(&list2, "Computer Science", 2);
    displayStudentLinkedList(list4);

}

// 1
StudentLinkedList getStudentsWithBirthMonth(StudentArrayList arrList, int month)
{
    StudentLinkedList linkedList = createStudentLinkedList();

    for (int i = 0; i < arrList.size; ++i)
    {
        if (arrList.arr[i].birthDate.month == month) {
            insertSortedStudentLinkedList(&linkedList, arrList.arr[i]);
        }
    }

    return linkedList;
}

// 2
StudentLinkedList removeStudents(StudentLinkedList *list, String program, int year)
{
    if (list == NULL) { return NULL; }

    StudentLinkedList linkedList = createStudentLinkedList();
    StudentNode **trav = list;
    
    while (*trav != NULL) 
    {
        if (
            (*trav)->val.level == year
            && strcmp((*trav)->val.program, program) == 0
        ) {
            insertSortedStudentLinkedList(&linkedList, (*trav)->val);
            *trav = (*trav)->next;
        }
        else 
        {
            trav = &(*trav)->next;
        }
    }

    return linkedList;
}
