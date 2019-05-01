#ifndef CHMOD_H
#define CHMOD_H

#include "commands/command.h"
#include "user.h"
#include "file.h"
#include "folder.h"

class Chmod : public Command
{
public:
    Chmod();
    Chmod(QList<QByteArray> args);
    void command_effect(Console* console, User* user) override;

private:
    File* getFileByname(const Folder* folder, const QByteArray& name);
};

#endif // CHMOD_H
