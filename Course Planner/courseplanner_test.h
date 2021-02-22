#ifndef COURSEPLANNER_TEST_H
#define COURSEPLANNER_TEST_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class CoursePlanner_Test; }
QT_END_NAMESPACE

class CoursePlanner_Test : public QMainWindow
{
    Q_OBJECT

public:
    CoursePlanner_Test(QWidget *parent = nullptr);
    ~CoursePlanner_Test();

private slots:
    void on_pushButton_2_clicked();

    void on_buton_busy_clicked();

    void on_pushButton_clicked();

    void on_button_create_clicked();

    void on_button_add_busy_clicked();

    void on_button_save_clicked();

private:
    Ui::CoursePlanner_Test *ui;
};
#endif // COURSEPLANNER_TEST_H
