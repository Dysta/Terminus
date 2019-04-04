#include "ls.h"


Ls::Ls()
    : Command(){}

Ls::Ls(QList<QByteArray> args)
    : Command(args) {}

void Ls::command_effect(){
    qDebug() << "Commande LS lancée !";
}
