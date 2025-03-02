#include <stdio.h>
#include <assert.h>
#include "date.h"

void testIsLeapYear() {
    assert(isLeapYear(2000) == 1);
    assert(isLeapYear(1900) == 0);
    assert(isLeapYear(2020) == 1);
    assert(isLeapYear(2021) == 0);
}

void testCreateDate() {
    _Date date = createDate(12, 5, 2023);
    assert(date.day == 12);
    assert(date.month == 5);
    assert(date.year == 2023);
}

void testGetDiffInDays() {
    _Date date1 = {1, 1, 2023};
    _Date date2 = {1, 1, 2024};
    _Date diff = getDiffInDays(date1, date2);
    // Assuming getDiffInDays returns the difference in days in the 'day' field
    assert(diff.day == 366); // Assuming non-leap year
}

void testDaysInMonth() {
    assert(daysInMonth(2, 2020) == 29); // Leap year
    assert(daysInMonth(2, 2021) == 28); // Non-leap year
}

int main() {
    testIsLeapYear();
    testCreateDate();
    displayDate(createDate(1, 5, 2025));
    testGetDiffInDays();
    testDaysInMonth();
    printf("All tests passed.\n");
    return 0;
}
