#include "error.h"

void throwError(String errMsg)
{
    if (errMsg != NULL) 
    {
        printf("%s\n", errMsg);
    }

    exit(1);
}
