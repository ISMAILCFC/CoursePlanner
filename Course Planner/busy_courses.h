#ifndef BUSY_COURSES_H
#define BUSY_COURSES_H
#include <QString>

class Busy_Courses
{
public:
    Busy_Courses();

    QString course_code,days,time_slot;
    Busy_Courses(QString,QString,QString);



    QString getCourse_code() const;
    void setCourse_code(const QString &value);
    QString getDays() const;
    void setDays(const QString &value);
    QString getTime_slot() const;
    void setTime_slot(const QString &value);
};

#endif // BUSY_COURSES_H
