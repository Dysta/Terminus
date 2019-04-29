#ifndef ECHO_H
#define ECHO_H

#include "commands/command.h"
#include "user.h"
#include "color.h"

class Echo : public Command
{
public:
    Echo();
    Echo(QList<QByteArray>);
    void command_effect(Console* console, User* user) override;
};

#endif // ECHO_H
