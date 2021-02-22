#ifndef READCSVFILE_H
#define READCSVFILE_H
#include <QVector>
#include <QString>



class readCsvFile
{
public:
    readCsvFile();
    QVector<QVector<QString >> splitToString(QString);
};

#endif // READCSVFILE_H
