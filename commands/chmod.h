#ifndef CHMOD_H
#define CHMOD_H

#include "commands/command.h"
#include "user.h"

class Chmod : public Command
{
public:
    Chmod();
    Chmod(QList<QByteArray>(args));
    void command_effect(Console* console, User* user) override;
};

#endif // CHMOD_H
