#ifndef COMMAND_H
#define COMMAND_H

#include <QString>
#include <QList>
#include <iostream>
#include <QDebug>

#include "folder.h"
#include "file.h"

class Command
{
public:
    Command();
    Command(QList<QByteArray> args);
    virtual ~Command();
    virtual void command_effect(Folder *f) = 0;

private:
    QList<QByteArray> _args;

};

#endif // COMMAND_H
