#ifndef COURSE_H
#define COURSE_H
#include<QString>

class course
{
public:
    //Default Constructor
    course();
    //Destructor
    ~course();
    //Overload Constructor
    course(QString, QString, QString, QString,QString, QString, QString);
    //Accessor Functions
    QString getCourseCode() const;
    QString getCourseName() const;
    QString getSemesterYear() const;
    QString getCredit() const;
    QString getCompulsoryOrElective() const;
    QString getDepartmentOrService() const;
    QString getProfessorName() const;
    //Mutator Functions
    void setCourseCode(const QString &value);
    void setCourseName(const QString &value);
    void setSemesterYear(const QString &value);
    void setCredit(const QString &value);
    void setCompulsoryOrElective(const QString &value);
    void setDepartmentOrService(const QString &value);
    void setProfessorName(const QString &value);




private:
    //Memmber Variables
    QString courseCode;
    QString courseName;
    QString semesterYear; //firstClass, SecondClass,..
    QString credit;
    QString compulsoryOrElective;
    QString departmentOrService;
    QString professorName;
public:
    bool isAssigned=false;


};

#endif // COURSE_H
