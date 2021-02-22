#include "read_courses.h"
#include <QVector>
#include <course.h>
#include <QFile>
#include <QDebug>

Read_Courses::Read_Courses()
{

}
QVector<course> vector_courses;//course_list vector

QStringList list_split;
QString line;
QVector<course> Read_Courses::readfile_courses()
{
    QFile file("C:/Users/degirmenci/Desktop/gui_test/courses.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        qDebug() << file.errorString();

    while (!file.atEnd()) {
        line = file.readLine();
        list_split =line.split(';');

        course c_obje(list_split[0],list_split[1],list_split[2],list_split[3],list_split[4],list_split[5],list_split[6]);
        vector_courses.push_back(c_obje);

    }
    list_split.clear();
    file.close();

    return vector_courses;
}
