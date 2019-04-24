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
    QString getName() const;
    QString getContent() const;

private:
    QString _name;
    QString _content;
};

#endif // FILE_H
