#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>
#include <stdlib.h>
#include "../string/myString.h"

void throwError(String errMsg)
{
    if (errMsg != NULL) 
    {
        printf("%s\n", errMsg);
    }

    exit(1);
}

#endif
