#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <QString>
#include <QList>
#include <iostream>
#include <QDebug>

#include "commands/ls.h"
#include "commands/cd.h"
#include "folder.h"

class InputParser
{
public:
    InputParser();
    void parse(QByteArray buffer, int htmlSize, Folder *currentFolder);
    void launchCommand(Folder *currentFolder);

private:
    QByteArray _cmd;
    QList<QByteArray> _args;

};

#endif // INPUTPARSER_H
