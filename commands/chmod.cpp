#include "chmod.h"
#include "console.h"

Chmod::Chmod()
{

}

Chmod::Chmod(QList<QByteArray> args)
    : Command(args) {}


void Chmod::command_effect(Console *console, User *user) {
    if (this->_args.isEmpty()) return;

    qDebug() << "ksjhkshgksgkdgh" <<  _args;
}
