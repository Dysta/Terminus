#ifndef FILE_H
#define FILE_H

#include <QString>
#include <QList>
#include <iostream>
#include <QDebug>

class File
{
public:
    File(QString name, QString content);
    QString toString();
private:
    QString name;
    QString content;
};

#endif // FILE_H
