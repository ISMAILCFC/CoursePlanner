#ifndef READ_COURSES_H
#define READ_COURSES_H
#include <QVector>
#include <course.h>


class Read_Courses
{
public:
    Read_Courses();
    QVector<course> readfile_courses();

};

#endif // READ_COURSES_H
