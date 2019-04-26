#include "cd.h"

Cd::Cd() :
    Command(){}

Cd::Cd(QList<QByteArray> args)
    : Command(args) {}

void Cd::command_effect(Folder *f){
    qDebug() << "Commande CD lancée !\n";
}
