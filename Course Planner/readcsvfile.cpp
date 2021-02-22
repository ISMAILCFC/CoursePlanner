#include "readcsvfile.h"
#include <QFile>
#include <QTextStream>
#include<QDebug>
#include <fstream>
readCsvFile::readCsvFile()
{

}

QVector<QVector<QString>> readCsvFile::splitToString(QString fileName)
{


    QFile mfile(fileName);
    if(!mfile.open(QFile::ReadOnly | QFile::Text)){
         qDebug() << "Error found :"<<"path="+fileName;
    }
    QTextStream in(&mfile);
    QVector<QVector<QString>> vline;
    QVector<QString> tokens;

    while(!in.atEnd()){
        QString line = in.readLine();
        for(int i=0; i<line.split(';').length(); i++){
            tokens.push_back(line.split(';').at(i));
        }
        vline.push_back(tokens);
        tokens.clear();
    }


    //    qDebug() << vline;
    mfile.close();
    return vline;


}
