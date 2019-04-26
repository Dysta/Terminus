#ifndef LS_H
#define LS_H

#include "command.h"
#include "user.h"

class Ls : public Command
{
public:
    Ls();
    Ls(QList<QByteArray>);
    void command_effect(User* user, Folder *f);
};

#endif // LS_H
