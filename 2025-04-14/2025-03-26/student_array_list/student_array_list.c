#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../student_array_list/student_array_list.h"

bool ensureExtraSpaceInArrayList(StudentArrayList *list);


StudentArrayList createStudentArrayList(int initCapacity)
{
    StudentArrayList instance;
    instance.arr = calloc(initCapacity, sizeof(Student));
    instance.size = 0;
    instance.capacity = initCapacity;

    return instance;
}

bool insertSortedStudentArrayList
(
    StudentArrayList *list,
    Student student
)
{
    
    if (list == NULL || !ensureExtraSpaceInArrayList(list)) { return false; }

    int i;
    for (i = list->size++; i > 0; --i)
    {
        if (
            strcmp(
                list->arr[i-1].name.lName,
                student.name.lName
            ) <= 0
        ) { break; }

        list->arr[i] = list->arr[i-1];
    }

    list->arr[i] = student;
    
    return true;
}

void displayStudentArrayList(StudentArrayList list)
{
    printf("ID, Name, Birth Day, Program & Year\n", "");
    
    for (int i = 0; i < list.size; ++i)
    {
        printf("%03d, ", i + 1);
        displayName(list.arr[i].name);
        printf(", ");
        displayDate(list.arr[i].birthDate);
        printf
        (
            ", %s - %02d\n",
            list.arr[i].program,
            list.arr[i].level
        );
    }
}

bool ensureExtraSpaceInArrayList(StudentArrayList *list)
{
    if (list->size < list->capacity) { return true; }

    Student *newArr = realloc
    (
        list->arr,
        (list->capacity << 1) * sizeof(Student)
    );
    if (newArr == NULL) { return false; }

    list->arr = newArr;
    list->capacity = list->capacity << 1;

    return true;
}
