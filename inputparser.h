#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <QString>
#include <QList>
#include <iostream>
#include <QDebug>

#include "commands/command.h"
#include "commands/cd.h"
#include "commands/ls.h"
#include "commands/cat.h"
#include "commands/echo.h"
#include "commands/chmod.h"

class InputParser
{
public:
    InputParser();
    void parse(QByteArray buffer, int htmlSize);
    void prepareCommand();

    Command *getCommand() const;
private:
    QByteArray _cmd;
    QList<QByteArray> _args;
    QList<QByteArray> _flags;

    Command* _command;

};

#endif // INPUTPARSER_H
