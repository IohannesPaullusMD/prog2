#include <stdio.h>
#include "my_header.h"
#include <stdlib.h>

#define EXIT 0
#define DISPLAY_LIST 1
#define INSERT_SORTED 2
#define GET_PRIMES 3

void displayCommands();
bool executeCommand(int command, List *list);
void handleInsertCommand(List *list);
void handleGetPrimesCommand(List *list);

int main()
{
    int command = 0;
    List list = createList();
    initList(&list);

    do
    {
        displayCommands();
        printf("Enter command ID: ");
        scanf("%d", &command);
    }
    while (executeCommand(command, &list));
}

void displayCommands()
{
    system("cls");
    printf
    (
        "%s%s%s%s%s",
        "Enter the ID of the command you want to execute.\n",
        "[0] exit\n",
        "[1] display list\n",
        "[2] insert sorted\n",
        "[3] get prime numbers in list\n"
    );
}

bool executeCommand(int command, List *list)
{
    printf("\n");
    switch (command)
    {
        case EXIT:
            return false;
        case DISPLAY_LIST:
            displayList(*list);
            break;
        case INSERT_SORTED:
            handleInsertCommand(list);
            break;
        case GET_PRIMES:
            handleGetPrimesCommand(list);
            break;
    }

    printf("\n");
    system("pause");
    return true;
}

void handleInsertCommand(List *list)
{
    int item = 0;
    printf("Enter element to insert: ");
    scanf("%d", &item);
    printf
    (
        "%s inserted: %d \n",
        insertSorted(list, item) ? "successfully" : "not successfully",
        item
    );
}

void handleGetPrimesCommand(List *list)
{
    printf("removed items:\n");
    displayList(getPrimeNumbers(list));

    displayList(*list);
}
