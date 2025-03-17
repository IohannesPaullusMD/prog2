#ifndef PARK_INFO
#define PARK_INFO

#include "../2025-02-19/time/time.h"

// #define 

// struct time
// {
//     int hour;
//     int min;
// };

struct parkInfo
{
    // struct time time_in;
    // struct time time_out;
    _Time timeIn;
    _Time timeOut;
};

typedef struct parkInfo _ParkingInfo;

/**
 * Note:
 * Vehicle Type     | First Rate (first 3hrs)   | Second Rate (after the first 3hrs)
 * ---------------------------------------------------------------------------------
 * Motorcycle (1)   | P 30.00                   | P 0.00
 * Sedan (2)        | P 30.00                   | P 5.00
 * SUV (3)          | P 45.00                   | P 3.00
 */

_ParkingInfo createParkingInfo(int vehicleType, _Time timeIn, _Time timeOut);

struct 

#endif
