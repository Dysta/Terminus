#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <QString>
#include <QList>
#include <iostream>
#include <QDebug>

#include "ls.h"

class InputParser
{
public:
    InputParser();
    void parse(QByteArray buffer, int htmlSize);
    void launchCommand();

private:
    QByteArray _cmd;
    QList<QByteArray> _args;


};

#endif // INPUTPARSER_H
