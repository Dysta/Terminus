#ifndef CD_H
#define CD_H

#include "commands/command.h"
#include "user.h"

class Cd : public Command
{
public:
    Cd();
    Cd(QList<QByteArray>);
    void command_effect(Console* console, User* user, Folder *f) override;
};

#endif // CD_H
