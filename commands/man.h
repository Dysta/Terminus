#ifndef MAN_H
#define MAN_H

#include <functional>
#include <QMap>

#include "commands/command.h"
#include "user.h"
#include "color.h"

using Func = std::function<void(Console*)>;

class Man : public Command
{
public:
    Man();
    Man(QList<QByteArray> args);
    void command_effect(Console* console, User* user) override;

private:
    static void man_man(Console* console);
    static void man_cd(Console* console);
    static void man_echo(Console* console);
    static void man_cat(Console* console);
    static void man_chmod(Console* console);
    static void man_ls(Console* console);
    static void man_mv(Console* console);
};

#endif // MAN_H
