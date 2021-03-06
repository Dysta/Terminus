#ifndef CAT_H
#define CAT_H

#include "commands/command.h"
#include "user.h"

class Cat : public Command
{
public:
    Cat();
    Cat(QList<QByteArray>);
    void command_effect(Console* console, User* user) override;
};

#endif // CAT_H
