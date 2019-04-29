#ifndef LS_H
#define LS_H

#include <QString>

#include "commands/command.h"
#include "user.h"
#include "color.h"

class Ls : public Command
{
public:
    Ls();
    Ls(QList<QByteArray>);
    void command_effect(Console* console, User* user);

private:
    QString getColorMode(int mode);
};

#endif // LS_H
