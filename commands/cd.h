#ifndef CD_H
#define CD_H

#include "command.h"

class Cd : public Command
{
public:
    Cd();
    Cd(QList<QByteArray>);
    void command_effect(Folder *f);
};

#endif // CD_H
