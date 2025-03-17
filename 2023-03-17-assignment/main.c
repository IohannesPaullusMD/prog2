#include <stdio.h>
#include <stdlib.h>

#include "my_header.h"

#define EXIT 0
#define DISPLAY_LIST 1
#define ADD_ELEMENT 2
#define REMOVE_ELEMENT 3
#define IS_EMPTY 4
#define IS_FULL 5
#define GET_ALL_PRIME_FACTORS 6

void displayCommands();
bool executeCommand(int command, ArrayList *list);
void addElementHandler(ArrayList *list);
void isEmptyHandler(ArrayList list);
void isFullHandler(ArrayList list);
void removeElementHandler(ArrayList *list);
void getAllPrimeFactorsHandler(ArrayList *list);


int main()
{
    int command = EXIT;
    ArrayList list = createList(1);

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
        "%s%s%s%s%s%s%s%s",
        "Enter the ID of the command you want to execute.\n",
        "[0] exit\n",
        "[1] display list\n",
        "[2] add element\n",
        "[3] remove element\n",
        "[4] isEmpty\n",
        "[5] isFull\n",
        "[6] remove all prime factors in list and display removed items\n"
    );
}

bool executeCommand(int command, ArrayList *list)
{
    printf("\n");
    switch (command)
    {
        case EXIT:
            return false;
        case DISPLAY_LIST:
            displayList(*list);
            break;
        case ADD_ELEMENT:
            addElementHandler(list);
            break;
        case REMOVE_ELEMENT:
            removeElementHandler(list);
            break;
        case IS_EMPTY:
            isEmptyHandler(*list);
            break;
        case IS_FULL:
            isFullHandler(*list);
            break;
        case GET_ALL_PRIME_FACTORS:
            getAllPrimeFactorsHandler(list);
            break;
    }

    printf("\n");
    system("pause");
    return true;
}

void addElementHandler(ArrayList *list)
{
    int element = 0;
    printf("Enter element to add: ");
    scanf("%d", &element);
    printf
    (
        "%s added element: %d\n",
        addElement(list, element) ? "Successfully" : "Not Successfully",
        element
    );
}

void isEmptyHandler(ArrayList list)
{
    printf("list is %s\n", isEmpty(list) ? "empty" : "not empty");
}

void isFullHandler(ArrayList list)
{
    printf("list is %s\n", isFull(list) ? "full" : "not full");
}

void removeElementHandler(ArrayList *list)
{
    int element = 0;
    printf("Enter element to remove: ");
    scanf("%d", &element);
    printf
    (
        "%s removed element: %d\n",
        addElement(list, element) ? "Successfully" : "Not Successfully",
        element
    );
}

void getAllPrimeFactorsHandler(ArrayList *list)
{
    int number = 0;
    printf("Enter number to find its prime factors in the list: ");
    scanf("%d", &number);

    printf("\nPrime factors of %d removed from the list:\n", number);
    displayList(getAllPrimeFactors(list, number));
}

