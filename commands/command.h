#ifndef COMMAND_H
#define COMMAND_H

#include <QString>
#include <QList>
#include <iostream>
#include <QDebug>

class Command
{
public:
    Command();
    Command(QList<QByteArray> args);
    virtual ~Command();
    virtual void command_effect();

private:
    QList<QByteArray> _args;

};

#endif // COMMAND_H
