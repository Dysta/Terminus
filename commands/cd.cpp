#include "cd.h"

Cd::Cd() :
    Command(){}

Cd::Cd(QList<QByteArray> args)
    : Command(args) {}

void Cd::command_effect(User* user, Folder *f){
    qDebug() << "Commande CD lancée !\n";
    qDebug() << this->_args;
    if (this->_args.isEmpty()) return;
    for (Folder* fo : f->children()) {
        if (fo->getName() == QString(this->_args.first()))
            user->setCurrentFolder(fo);
    }
    qDebug() << "Dossier inexistant";


}
