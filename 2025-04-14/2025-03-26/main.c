#include <stdio.h>

#include "./student_array_list/student_array_list.h"
#include "./student_linked_list/student_linked_list.h"

int main()
{
    Student student1 = createStudent(0, createName("John", "Iohann", "Doea"), createDate(1, 1, 2020), "Computer Science", 1);
    Student student2 = createStudent(1, createName("Jane", "Iohanna", "Doeb"), createDate(2, 1, 2000), "Computer Science", 1);
    Student student3 = createStudent(2, createName("Alice", "Iohanna", "Doec"), createDate(3, 3, 2005), "Computer Science", 1);
    Student student4 = createStudent(3, createName("Bob", "Iohanna", "Doed"), createDate(2, 1, 2000), "Computer Science", 1);
    Student student5 = createStudent(4, createName("Charlie", "Iohanna", "Doee"), createDate(5, 5, 2000), "Computer Science", 1);
    
    StudentArrayList list = createStudentArrayList(5);
    insertSortedStudentArrayList(&list, student5);
    insertSortedStudentArrayList(&list, student4);
    insertSortedStudentArrayList(&list, student3);
    insertSortedStudentArrayList(&list, student2);
    insertSortedStudentArrayList(&list, student1);
    displayStudentArrayList(list);
    printf("\n\n");
    
    StudentLinkedList list2 = createStudentLinkedList();
    insertSortedStudentLinkedList(&list2, student5);
    insertSortedStudentLinkedList(&list2, student1);
    insertSortedStudentLinkedList(&list2, student3);
    insertSortedStudentLinkedList(&list2, student2);
    insertSortedStudentLinkedList(&list2, student4);
    displayStudentLinkedList(list2);
    printf("\n\n");

    return 0;
}
