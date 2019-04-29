#ifndef LS_H
#define LS_H

#include <QString>

#include "command.h"
#include "user.h"

class Ls : public Command
{
public:
    Ls();
    Ls(QList<QByteArray>);
    void command_effect(Console* console, User* user, Folder *f);
};

#endif // LS_H
