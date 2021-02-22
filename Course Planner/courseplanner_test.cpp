#include "courseplanner_test.h"
#include "ui_courseplanner_test.h"
#include <QFile>
#include <QDebug>
#include <course.h>
#include <read_courses.h>
#include <busy_courses.h>
#include <writeschedule.h>
#include <day.h>
#include <readcsvfile.h>
#include <QTextEdit>


QVector<day> schedule(5);
QVector <course> course_vector;
QVector  <Busy_Courses> busy_vector;
QVector <QVector <QString> > schedule_writer;
int row_mon_morn=0; //row count for morning,day
int row_mon_af=0; //row count for afternoon,day
QString course_path;
QString service_path;
QString *last_course_path;
QString *last_service_path;

void fillVectorOfCourse(QVector<course>&);
void fillVectorOfScheduleWithService( QVector<day>&,QVector<course>&);
void fillVectorOfBusy(QVector<QString>&);
void printVectorOfCourse(const QVector<course>&);
int getNumberOfDay(QString);
void fillVectorOfScheduleWithDepartment( QVector<day>&, QVector<course>&, QVector<QVector<QString>>&);
bool isSameTimeSlotMorningForClass(day& dayValue, course& courseValue);
bool isSameTimeSlotAfternoonForClass(day& dayValue, course& courseValue);
bool isBusyOrNotCourseMorning(course& courseValue, int dayIndex, QVector<QVector<QString>>& busyTimeSlot);
bool isBusyOrNotCourseAfternoon(course& courseValue, int dayIndex, QVector<QVector<QString>>& busyTimeSlot);
void printSchedule(const QVector<day>&);

CoursePlanner_Test::~CoursePlanner_Test()
{
    delete ui;

}

int getNumberOfDay(QString dayValue){
    if(dayValue=="Monday") return 0;
    if(dayValue=="Tuesday") return 1;
    if(dayValue=="Wednesday") return 2;
    if(dayValue=="Thursday") return 3;
    if(dayValue=="Friday") return 4;
    else return -1;
}

void fillVectorOfScheduleWithDepartment( QVector<day>& schedule, QVector<course>& myCourse, QVector<QVector<QString>>& busyTimeSlot){
    for (int i=0; i<myCourse.size(); i++) {
        if(myCourse[i].isAssigned==true){
            continue;
        }

        bool isElective = myCourse[i].getCompulsoryOrElective() == "E" ? true : false;
        for (int dayIndex = 0; dayIndex<5; dayIndex++) {

            bool isSameClassMorningForNow = isSameTimeSlotMorningForClass(schedule[dayIndex], myCourse[i]);
            bool isSameClassAfternoonForNow = isSameTimeSlotAfternoonForClass(schedule[dayIndex], myCourse[i]);

            bool isBusyOrNotCourseMorningNow = isBusyOrNotCourseMorning(myCourse[i], dayIndex, busyTimeSlot);
            bool isBusyOrNotCourseAfternoonNow = isBusyOrNotCourseAfternoon(myCourse[i], dayIndex, busyTimeSlot);

            if ( isSameClassMorningForNow == true && isSameClassAfternoonForNow == true )
                continue;

            if ( isBusyOrNotCourseMorningNow == true && isBusyOrNotCourseAfternoonNow == true )
                continue;

            if ( isSameClassMorningForNow == false && isBusyOrNotCourseMorningNow == false )
            {
                if ( isElective )
                {
                    if(schedule[dayIndex].morning.smallClassroom1 == false){
                        schedule[dayIndex].morning.smallClassroom1 = true;
                        myCourse[i].isAssigned = true;
                        schedule[dayIndex].morning.smallClassroom1Course = myCourse[i];
                    }
                    else if(schedule[dayIndex].morning.smallClassroom2 == false){
                        schedule[dayIndex].morning.smallClassroom2= true;
                        myCourse[i].isAssigned = true;
                        schedule[dayIndex].morning.smallClassroom2Course = myCourse[i];
                    }
                    else if(schedule[dayIndex].morning.bigClassroom1 == false){
                        schedule[dayIndex].morning.bigClassroom1 = true;
                        myCourse[i].isAssigned = true;
                        schedule[dayIndex].morning.bigClassroom1Course = myCourse[i];
                    }
                    else if(schedule[dayIndex].morning.bigClassroom2 == false){
                        schedule[dayIndex].morning.bigClassroom2 = true;
                        myCourse[i].isAssigned = true;
                        schedule[dayIndex].morning.bigClassroom2Course = myCourse[i];
                    }

                }
                else { //Compulsory
                    if(schedule[dayIndex].morning.bigClassroom1 == false){
                        schedule[dayIndex].morning.bigClassroom1 = true;
                        myCourse[i].isAssigned = true;
                        schedule[dayIndex].morning.bigClassroom1Course = myCourse[i];
                    }
                    else if(schedule[dayIndex].morning.bigClassroom2 == false){
                        schedule[dayIndex].morning.bigClassroom2 = true;
                        myCourse[i].isAssigned = true;
                        schedule[dayIndex].morning.bigClassroom2Course = myCourse[i];
                    }
                }
            }
            else if ( isSameClassAfternoonForNow == false && isBusyOrNotCourseAfternoonNow == false  )
            {
                if ( isElective )
                {
                    if(schedule[dayIndex].afternoon.smallClassroom1 == false){
                        schedule[dayIndex].afternoon.smallClassroom1 = true;
                        myCourse[i].isAssigned = true;
                        schedule[dayIndex].afternoon.smallClassroom1Course = myCourse[i];

                    }
                    else if(schedule[dayIndex].afternoon.smallClassroom2 == false){
                        schedule[dayIndex].afternoon.smallClassroom2= true;
                        myCourse[i].isAssigned = true;
                        schedule[dayIndex].afternoon.smallClassroom2Course = myCourse[i];
                    }
                    else if(schedule[dayIndex].afternoon.bigClassroom1 == false){
                        schedule[dayIndex].afternoon.bigClassroom1 = true;
                        myCourse[i].isAssigned = true;
                        schedule[dayIndex].afternoon.bigClassroom1Course = myCourse[i];
                    }
                    else if(schedule[dayIndex].afternoon.bigClassroom2 == false){
                        schedule[dayIndex].afternoon.bigClassroom2 = true;
                        myCourse[i].isAssigned = true;
                        schedule[dayIndex].afternoon.bigClassroom2Course = myCourse[i];
                    }

                }
                else { //compulsory
                    if(schedule[dayIndex].afternoon.bigClassroom1 == false){
                        schedule[dayIndex].afternoon.bigClassroom1 = true;
                        myCourse[i].isAssigned = true;
                        schedule[dayIndex].afternoon.bigClassroom1Course = myCourse[i];
                    }
                    else if(schedule[dayIndex].afternoon.bigClassroom2 == false){
                        schedule[dayIndex].afternoon.bigClassroom2 = true;
                        myCourse[i].isAssigned = true;
                        schedule[dayIndex].afternoon.bigClassroom2Course = myCourse[i];
                    }
                }
            }

        }

    }
}

void fillVectorOfScheduleWithService( QVector<day>& schedule, QVector<course>& myCourse){

    readCsvFile readcsv;
     QString service_path="C:/Users/degirmenci/Desktop/gui_test/service.csv";
     //QString service_path=*last_service_path;

    QVector<QVector<QString>> serviceCourse = readcsv.splitToString(service_path);

    for (int i=0; i<serviceCourse.size(); i++) {
        int courseIndex=-1;
        for (int j = 0; j < myCourse.size(); ++j) {
            if (myCourse[j].getCourseCode()== serviceCourse[i][0]) {
                courseIndex=j;
                break;
            }
        }
        int dayIndex = getNumberOfDay(serviceCourse[i][1]);
        bool isElective = myCourse[courseIndex].getCompulsoryOrElective() == "E" ? true : false;

        if( serviceCourse[i][2] == "Afternoon" )
        {
            if ( isElective )
            {
                if(schedule[dayIndex].afternoon.smallClassroom1 == false){
                    schedule[dayIndex].afternoon.smallClassroom1 = true;
                    myCourse[courseIndex].isAssigned = true;
                    schedule[dayIndex].afternoon.smallClassroom1Course = myCourse[courseIndex];

                }
                else if(schedule[dayIndex].afternoon.smallClassroom2 == false){
                    schedule[dayIndex].afternoon.smallClassroom2= true;
                    myCourse[courseIndex].isAssigned = true;
                    schedule[dayIndex].afternoon.smallClassroom2Course = myCourse[courseIndex];
                }
                else if(schedule[dayIndex].afternoon.bigClassroom1 == false){
                    schedule[dayIndex].afternoon.bigClassroom1 = true;
                    myCourse[courseIndex].isAssigned = true;
                    schedule[dayIndex].afternoon.bigClassroom1Course = myCourse[courseIndex];
                }
                else if(schedule[dayIndex].afternoon.bigClassroom2 == false){
                    schedule[dayIndex].afternoon.bigClassroom2 = true;
                    myCourse[courseIndex].isAssigned = true;
                    schedule[dayIndex].afternoon.bigClassroom2Course = myCourse[courseIndex];
                }

            }
            else { //compulsory
                if(schedule[dayIndex].afternoon.bigClassroom1 == false){
                    schedule[dayIndex].afternoon.bigClassroom1 = true;
                    myCourse[courseIndex].isAssigned = true;
                    schedule[dayIndex].afternoon.bigClassroom1Course = myCourse[courseIndex];
                }
                else if(schedule[dayIndex].afternoon.bigClassroom2 == false){
                    schedule[dayIndex].afternoon.bigClassroom2 = true;
                    myCourse[courseIndex].isAssigned = true;
                    schedule[dayIndex].afternoon.bigClassroom2Course = myCourse[courseIndex];
                }
            }
        }
        else if(serviceCourse[i][2] == "Morning")
        {
            if ( isElective )
            {
                if(schedule[dayIndex].morning.smallClassroom1 == false){
                    schedule[dayIndex].morning.smallClassroom1 = true;
                    myCourse[courseIndex].isAssigned = true;
                    schedule[dayIndex].morning.smallClassroom1Course = myCourse[courseIndex];
                }
                else if(schedule[dayIndex].morning.smallClassroom2 == false){
                    schedule[dayIndex].morning.smallClassroom2= true;
                    myCourse[courseIndex].isAssigned = true;
                    schedule[dayIndex].morning.smallClassroom2Course = myCourse[courseIndex];
                }
                else if(schedule[dayIndex].morning.bigClassroom1 == false){
                    schedule[dayIndex].morning.bigClassroom1 = true;
                    myCourse[courseIndex].isAssigned = true;
                    schedule[dayIndex].morning.bigClassroom1Course = myCourse[courseIndex];
                }
                else if(schedule[dayIndex].morning.bigClassroom2 == false){
                    schedule[dayIndex].morning.bigClassroom2 = true;
                    myCourse[courseIndex].isAssigned = true;
                    schedule[dayIndex].morning.bigClassroom2Course = myCourse[courseIndex];
                }

            }
            else { //Compulsory
                if(schedule[dayIndex].morning.bigClassroom1 == false){
                    schedule[dayIndex].morning.bigClassroom1 = true;
                    myCourse[courseIndex].isAssigned = true;
                    schedule[dayIndex].morning.bigClassroom1Course = myCourse[courseIndex];
                }
                else if(schedule[dayIndex].morning.bigClassroom2 == false){
                    schedule[dayIndex].morning.bigClassroom2 = true;
                    myCourse[courseIndex].isAssigned = true;
                    schedule[dayIndex].morning.bigClassroom2Course = myCourse[courseIndex];
                }
            }

        }
    }



}

bool isSameTimeSlotMorningForClass(day& dayValue, course& courseValue)
{
    bool returnedValue = false;

    if ( dayValue.morning.bigClassroom1 == true &&
        dayValue.morning.bigClassroom1Course.getSemesterYear() == courseValue.getSemesterYear() )
        returnedValue = true;

    if ( dayValue.morning.bigClassroom2 == true &&
        dayValue.morning.bigClassroom2Course.getSemesterYear() == courseValue.getSemesterYear() )
        returnedValue = true;

    if ( dayValue.morning.smallClassroom1 == true &&
        dayValue.morning.smallClassroom1Course.getSemesterYear() == courseValue.getSemesterYear() )
        returnedValue = true;

    if ( dayValue.morning.smallClassroom2 == true &&
        dayValue.morning.smallClassroom2Course.getSemesterYear() == courseValue.getSemesterYear() )
        returnedValue = true;

    return returnedValue;

}
bool isSameTimeSlotAfternoonForClass(day& dayValue, course& courseValue)
{
    bool returnedValue = false;

    if ( dayValue.afternoon.bigClassroom1 == true &&
        dayValue.afternoon.bigClassroom1Course.getSemesterYear() == courseValue.getSemesterYear() )
        returnedValue = true;

    if ( dayValue.afternoon.bigClassroom2 == true &&
        dayValue.afternoon.bigClassroom2Course.getSemesterYear() == courseValue.getSemesterYear() )
        returnedValue = true;

    if ( dayValue.afternoon.smallClassroom1 == true &&
        dayValue.afternoon.smallClassroom1Course.getSemesterYear() == courseValue.getSemesterYear() )
        returnedValue = true;

    if ( dayValue.afternoon.smallClassroom2 == true &&
        dayValue.afternoon.smallClassroom2Course.getSemesterYear() == courseValue.getSemesterYear() )
        returnedValue = true;

    return returnedValue;
}

bool isBusyOrNotCourseMorning(course& courseValue, int dayIndex, QVector<QVector<QString>>& busyTimeSlot)
{
    bool returnedValue = false;
    for ( int i = 0; i < busyTimeSlot.size() ; ++i )
    {
        int busyTimeSlotDayIndex = getNumberOfDay(busyTimeSlot[i][1]);
        if ( courseValue.getCourseCode() == busyTimeSlot[i][0] && dayIndex == busyTimeSlotDayIndex &&
            busyTimeSlot[i][2] == "Morning" )
        {
            returnedValue = true;
            break;
        }
    }

    return returnedValue;

}

bool isBusyOrNotCourseAfternoon(course& courseValue, int dayIndex, QVector<QVector<QString>>& busyTimeSlot)
{
    bool returnedValue = false;
    for ( int i = 0; i < busyTimeSlot.size() ; ++i )
    {
        int busyTimeSlotDayIndex = getNumberOfDay(busyTimeSlot[i][1]);
        if ( courseValue.getCourseCode() == busyTimeSlot[i][0] && dayIndex == busyTimeSlotDayIndex &&
            busyTimeSlot[i][2] == "Afternoon" )
        {
            returnedValue = true;
            break;
        }
    }

    return returnedValue;
}

void fillVectorOfCourse(QVector<course>& newMyCourse){
    readCsvFile readcsv;

    QString course_path="C:/Users/degirmenci/Desktop/gui_test/courses.csv";
    //QString course_path=*last_course_path;
    readcsv.splitToString(course_path);
    int z=0;
    for (int k=0; k<readcsv.splitToString(course_path).size(); k++) {
        course newCourse(readcsv.splitToString(course_path)[k][z], readcsv.splitToString(course_path)[k][z+1],
                         readcsv.splitToString(course_path)[k][z+2], readcsv.splitToString(course_path)[k][z+3],
                         readcsv.splitToString(course_path)[k][z+4], readcsv.splitToString(course_path)[k][z+5],
                         readcsv.splitToString(course_path)[k][z+6]);

        newMyCourse.push_back(newCourse);
    }


}
void CoursePlanner_Test::on_buton_busy_clicked()
{

    if(ui->groupBox->isVisible())
    {
        ui->groupBox->setVisible(false);
    }
    else{
            ui->groupBox->setVisible(true);
    }




    QStringList day_list={"Monday","Tuesday","Wednesday","Thursday","Friday"};

    ui->combo_courses->clear();
    ui->combo_day->clear();
    ui->combo_timeslot->clear();



    for (int i=0;i<course_vector.size();i++)
    {
        ui->combo_courses->addItem(course_vector.at(i).getCourseCode());
    }
    ui->combo_day->addItems(day_list);
    ui->combo_timeslot->addItem("Morning");
    ui->combo_timeslot->addItem("Afternoon");

}


CoursePlanner_Test::CoursePlanner_Test(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CoursePlanner_Test)
{

    ui->setupUi(this);
    Read_Courses read_file;
    course_vector=read_file.readfile_courses();
    QVector<course> myCourse;
    fillVectorOfCourse(myCourse);
     ui->groupBox->setVisible(false);

    schedule[0].dayName = "Monday";
    schedule[1].dayName = "Tuesday";
    schedule[2].dayName = "Wednesday";
    schedule[3].dayName = "Thursday";
    schedule[4].dayName = "Friday";

    QVector<QVector<QString>> busyTimeSlot = readCsvFile().splitToString("C:/Users/degirmenci/Desktop/gui_test//busy_output.csv");
    fillVectorOfScheduleWithService(schedule,myCourse);
    fillVectorOfScheduleWithDepartment(schedule, myCourse, busyTimeSlot);

}


void CoursePlanner_Test::on_button_create_clicked()
{

    for (int i=0;i<schedule.size();i++) {

                if ( schedule[i].morning.bigClassroom1 == true )
        {  ui->table_morning->setItem(row_mon_morn++,i,new QTableWidgetItem(schedule[i].morning.bigClassroom1Course.getCourseCode()+"\n"+"bigClassroom1"));
                  ui->table_morning->resizeRowsToContents();
                }
                    if ( schedule[i].morning.bigClassroom2 == true )
                       ui->table_morning->setItem(row_mon_morn++,i,new QTableWidgetItem(schedule[i].morning.bigClassroom2Course.getCourseCode()+"\n"+"bigClassroom2"));
                if ( schedule[i].morning.smallClassroom1 == true )
                       ui->table_morning->setItem(row_mon_morn++,i,new QTableWidgetItem(schedule[i].morning.smallClassroom1Course.getCourseCode()+"\n"+"smallClassroom1"));
                if ( schedule[i].morning.smallClassroom2 == true )
                       ui->table_morning->setItem(row_mon_morn++,i,new QTableWidgetItem(schedule[i].morning.smallClassroom2Course.getCourseCode()+"\n"+"smallClassroom2"));

                if ( schedule[i].afternoon.bigClassroom1 == true )
                {
                     ui->table_afternoon->setItem(row_mon_af++,i,new QTableWidgetItem(schedule[i].afternoon.bigClassroom1Course.getCourseCode()+"\n"+"bigClassroom1"));
                     ui->table_afternoon->resizeRowsToContents();
                }
                if ( schedule[i].afternoon.bigClassroom2 == true )
                       ui->table_afternoon->setItem(row_mon_af++,i,new QTableWidgetItem(schedule[i].afternoon.bigClassroom2Course.getCourseCode()+"\n"+"bigClassroom2"));
                if ( schedule[i].afternoon.smallClassroom1 == true )
                       ui->table_afternoon->setItem(row_mon_af++,i,new QTableWidgetItem(schedule[i].afternoon.smallClassroom1Course.getCourseCode()+"\n"+"smallClassroom1"));
                if ( schedule[i].afternoon.smallClassroom2 == true )
                      ui->table_afternoon->setItem(row_mon_af++,i,new QTableWidgetItem(schedule[i].afternoon.smallClassroom2Course.getCourseCode()+"\n"+"smallClassroom2"));


        row_mon_af=0;
        row_mon_morn=0;


    }





}

void CoursePlanner_Test::on_button_add_busy_clicked()
{
    QString course_code=ui->combo_courses->currentText();
    QString day=ui->combo_day->currentText();
    QString time_slot=ui->combo_timeslot->currentText();

    Busy_Courses b1(course_code,day,time_slot);
    busy_vector.push_back(b1);

    QFile mfile("C:/Users/degirmenci/Desktop/gui_test/busy_output.csv");

    if(!mfile.open(QFile::WriteOnly | QFile::Text))
    {
        qDebug() <<"Error Found ! :"<< mfile.errorString();
    }

    QTextStream out(&mfile);
    for (int i=0;i<busy_vector.size();i++) {

        out<<busy_vector.at(i).getCourse_code()+";"+busy_vector.at(i).getDays()+";"+busy_vector.at(i).getTime_slot()+"\n";
        ui->label->setText(busy_vector.at(i).getCourse_code()+" is added successfully !");
    }

}


void CoursePlanner_Test::on_button_save_clicked()
{
    course_path=ui->textEdit->toPlainText();
    service_path=ui->textEdit_2->toPlainText();

     QString newcourse_path='"'+course_path+'"';
     QString newservice_path='"'+service_path+'"';

     *last_course_path=newcourse_path.replace("\\","/");
     *last_service_path=newservice_path.replace("\\","/");

     ui->label_5->setText(newservice_path + "\n"+ newcourse_path);

}

