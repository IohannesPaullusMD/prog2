#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../student_array_list/student_array_list.h"

bool ensureExtraSpaceInArrayList(StudentArrayList list);


StudentArrayList newStudentArrayList(int initCapacity)
{
    StudentArrayList instance = calloc(1, sizeof(_StudentArrayList));
    if (instance == NULL) { return NULL; }

    _Student *arr = calloc(initCapacity, sizeof(_Student));
    if (arr == NULL) { free(instance); return NULL; }

    instance->arr = arr;
    instance->capacity = initCapacity;

    return instance;
}

bool insertSortedStudentArrayList
(
    StudentArrayList list,
    Student student
)
{
    
    if (list == NULL || !ensureExtraSpaceInArrayList(list)) { return false; }

    int i;
    for (i = list->size++; i > 0; --i)
    {
        if (
            strcmp(
                &list->arr[i-1].name->lName,
                &student->name->lName
            ) >= 0
        ) { break; }

        list->arr[i] = list->arr[i-1];
    }

    list->arr[i] = *student;
    
    return true;
}

void displayStudentArrayList(StudentArrayList list)
{
    printf("ID  |Name%26s |Birth Day   |Program & Year\n", "");
    
    for (int i = 0; i < list->size; ++i)
    {
        printf("%03d |");
        displayName(list->arr[i].name);
        printf(" |");
        displayDate(list->arr[i].birthDate);
        printf
        (
            " |%s - %02d\n",
            list->arr[i].program,
            list->arr[i].program
        );
    }
}

bool ensureExtraSpaceInArrayList(StudentArrayList list)
{
    if (list->size < list->capacity) { return true; }

    _Student *newArr = realloc
    (
        list,
        (list->capacity << 1) * sizeof(_Student)
    );
    if (newArr == NULL) { return false; }

    list->arr = newArr;
    list->capacity = list->capacity << 1;

    return true;
}
