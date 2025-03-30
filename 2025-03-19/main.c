#include <stdio.h>

#include "time/time.h"
#include "time_list/time_list.h"

ArrayList getTestList();

int main()
{
    ArrayList list = getTestList();
    Time testTime = newTime(12,0);

    printf("Test list:\n");
    displayList(list);
    printf("Test time: ");
    displayTime(testTime);

    printf("\nlist sorted nearest to time: ");
    displayTime(testTime);
    sortToNearestTime(testTime, &list);
    displayList(list);
}

ArrayList getTestList()
{
    ArrayList list = newList(5);
    addElement(&list, newTime(7,30));
    addElement(&list, newTime(18,20));
    addElement(&list, newTime(15,12));
    addElement(&list, newTime(2,30));
    addElement(&list, newTime(6,30));
    return list;
}
