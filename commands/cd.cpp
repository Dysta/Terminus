#include "cd.h"
#include "console.h"

Cd::Cd() :
    Command(){}

Cd::Cd(QList<QByteArray> args)
    : Command(args) {}

void Cd::command_effect(Console* console, User* user, Folder *f){
    qDebug() << "Commande CD lancée !\n";
    qDebug() << this->_args;

    if (this->_args.isEmpty()) {
        while(user->currentFolder()->getParent() != nullptr) {
            user->setCurrentFolder(user->currentFolder()->getParent());
        }
        return;
    }

    if (this->_args.first() == ".." && user->currentFolder()->getParent() != nullptr) {
        user->setCurrentFolder(user->currentFolder()->getParent());
        return;
    }

    for (Folder* fo : f->children()) {
        if (fo->getName() == QString(this->_args.first())) {
            user->setCurrentFolder(fo);
            return;
        }
    }

    console->appendHtml("Aucun fichier ou dossier de ce type");
}
