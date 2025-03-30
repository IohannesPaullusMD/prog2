#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "name.h"

Name createName(String fName, String mName, String lName)
{
    Name instance;

    strcpy(instance.fName, fName);
    strcpy(instance.mName, mName);
    strcpy(instance.lName, lName);

    return instance;
}

void displayName(Name name) 
{
    printf
    (
        "%s, %s %c.",
        name.lName,
        name.fName,
        name.mName[0]
    );
}
