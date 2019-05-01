#ifndef MV_H
#define MV_H

#include "command.h"

class Mv : public Command
{
public:
    Mv();
    Mv(QList<QByteArray>);
    void command_effect(Console* console, User* user);
};

#endif // MV_H
