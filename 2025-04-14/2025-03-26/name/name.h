#ifndef NAME_H
#define NAME_H

#include "../string/my_string.h"

typedef struct 
{
    String fName;
    String mName;
    String lName;
} 
Name, *NamePtr;

Name createName(String fName, String mName, String lName);

/**
 * LastName, FirstName Mi
 */ 
void displayName(Name name);

#endif
