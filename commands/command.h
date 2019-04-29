#ifndef COMMAND_H
#define COMMAND_H

#include <QString>
#include <QList>
#include <iostream>
#include <QDebug>

class Console;

#include "user.h"
#include "folder.h"
#include "file.h"

class Command
{
public:
    Command();
    Command(QList<QByteArray> args);
    virtual ~Command();
    virtual void command_effect(Console* console, User* user, Folder *f) = 0;

protected:
    QList<QByteArray> _args;

};

#endif // COMMAND_H
