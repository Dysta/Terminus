#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <QString>
#include <QList>
#include <iostream>
#include <QDebug>

class InputParser
{
public:
    InputParser();
    void parser(QByteArray buffer);

private:
    QString _cmd;
    QList<QString> _args;


};

#endif // INPUTPARSER_H
