#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int val;
    struct node *next;
} NodeType, *NodePtr;

bool insertFirst(NodePtr *headPtr, int val)
{
    if (headPtr == NULL) { return false; }

    NodePtr newNode = malloc(sizeof(NodeType));
    if (newNode == NULL) { return false; }
    
    newNode->val =  val; 
    newNode->next = *headPtr;
    *headPtr = newNode;
    return true;
}

bool insertLast(NodePtr *headPtr, int val)
{
    if (headPtr == NULL) { return false; }

    NodePtr *trav;
    NodePtr newNode = malloc(sizeof(NodeType));
    if (newNode == NULL) { return false; }

    for (
        trav = headPtr; 
        *trav != NULL; 
        trav = &(*trav)->next 
    ) {}

    newNode->next = NULL;
    *trav = newNode;
    return true;
}

