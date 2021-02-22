#include "busy_courses.h"

Busy_Courses::Busy_Courses()
{

}
Busy_Courses::Busy_Courses(QString course_code, QString days, QString time_slot)
{
    this->course_code = course_code;
    this->days=days;
    this->time_slot = time_slot;

}





QString Busy_Courses::getTime_slot() const
{
    return time_slot;
}

void Busy_Courses::setTime_slot(const QString &value)
{
    time_slot = value;
}

QString Busy_Courses::getDays() const
{
    return days;
}

void Busy_Courses::setDays(const QString &value)
{
    days = value;
}

QString Busy_Courses::getCourse_code() const
{
    return course_code;
}

void Busy_Courses::setCourse_code(const QString &value)
{
    course_code = value;
}
