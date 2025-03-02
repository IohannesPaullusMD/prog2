#include <stdio.h>
#include <assert.h>
#include "time.h"

void testCreateTime() {
    Time time = createTime(14, 30);
    assert(time->hours == 14);
    assert(time->minutes == 30);
}

void testGetTimeDiffInMinutes() {
    _Time time1 = {14, 30};
    _Time time2 = {16, 45};
    long64 diff = getTimeDiffInMinutes(time1, time2);
    assert(diff == 135); // (2 hours * 60) + 15 minutes
}

void testGetTimeDiffInHoursAndMinutes() {
    _Time time1 = {14, 30};
    _Time time2 = {16, 45};
    Time diff = getTimeDiffInHoursAndMinutes(time1, time2);
    displayTime(*diff);
    assert(diff->hours == 2);
    assert(diff->minutes == 15);
}

void testConvertToMinutes() {
    _Time time = {2, 30};
    long64 minutes = convertToMinutes(time);
    assert(minutes == 150); // (2 hours * 60) + 30 minutes
}

int main() {
    testCreateTime();
    displayTime(*createTime(14, 30));
    displayStandardTime(*createTime(14, 30));
    testGetTimeDiffInMinutes();
    testGetTimeDiffInHoursAndMinutes();
    testConvertToMinutes();
    printf("All tests passed.\n");
    return 0;
}
