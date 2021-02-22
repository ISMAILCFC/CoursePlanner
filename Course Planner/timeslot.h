#ifndef TIMESLOT_H
#define TIMESLOT_H
#include <course.h>

class timeSlot
{
public:
    timeSlot();
    course bigClassroom1Course;
    course bigClassroom2Course;
    course smallClassroom1Course;
    course smallClassroom2Course;
    bool bigClassroom1=false;
    bool bigClassroom2=false;
    bool smallClassroom1=false;
    bool smallClassroom2=false;
};

#endif // TIMESLOT_H
