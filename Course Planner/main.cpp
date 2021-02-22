#include <QApplication>
#include <readcsvfile.h>
#include <course.h>
#include <QDebug>
#include <iostream>
#include <QVector>
#include <day.h>
#include <writeschedule.h>
#include "courseplanner_test.h"



using namespace std;



int main(int argc, char *argv[])
{
   QApplication a(argc, argv);

    CoursePlanner_Test w;
    w.show();
    return a.exec();




}



