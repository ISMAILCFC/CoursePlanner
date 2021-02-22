#ifndef DAY_H
#define DAY_H
#include <timeslot.h>

class day
{
public:
    day();
    timeSlot morning;
    timeSlot afternoon;
    QString dayName;
};

#endif // DAY_H
