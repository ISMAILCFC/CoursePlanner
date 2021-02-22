#include "course.h"

course::course()
{

}

course::~course()
{

}

course::course(QString courseCode, QString courseName, QString semesterYear, QString credit, QString compulsoryOrElective, QString departmentOrService, QString professorName)
{
    this->courseCode = courseCode;
    this->courseName = courseName;
    this->semesterYear = semesterYear;
    this->credit = credit;
    this->compulsoryOrElective = compulsoryOrElective;
    this->departmentOrService = departmentOrService;
    this->professorName = professorName;
}

QString course::getCourseCode() const
{
    return courseCode;
}

void course::setCourseCode(const QString &value)
{
    courseCode = value;
}

QString course::getCourseName() const
{
    return courseName;
}

void course::setCourseName(const QString &value)
{
    courseName = value;
}

QString course::getSemesterYear() const
{
    return semesterYear;
}

void course::setSemesterYear(const QString &value)
{
    semesterYear = value;
}

QString course::getCredit() const
{
    return credit;
}

void course::setCredit(const QString &value)
{
    credit = value;
}

QString course::getCompulsoryOrElective() const
{
    return compulsoryOrElective;
}

void course::setCompulsoryOrElective(const QString &value)
{
    compulsoryOrElective = value;
}

QString course::getDepartmentOrService() const
{
    return departmentOrService;
}

void course::setDepartmentOrService(const QString &value)
{
    departmentOrService = value;
}

QString course::getProfessorName() const
{
    return professorName;
}

void course::setProfessorName(const QString &value)
{
    professorName = value;
}
