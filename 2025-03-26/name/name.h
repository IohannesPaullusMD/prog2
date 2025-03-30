#ifndef NAME_H
#define NAME_H

#include "../string/string.h"

typedef struct 
{
    String fName;
    String mName;
    String lName;
} 
_Name, *Name;

Name newName(String fName, String mName, String lName);

/**
 * LastName, FirstName Mi
 */ 
void displayName(Name name);

#endif
