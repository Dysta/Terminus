#include "mv.h"

Mv::Mv() : Command (){}

Mv::Mv(QList<QByteArray> args) : Command(args){}

void Mv::command_effect(Console *console, User *user){
    qDebug() << "Commande MV lancée !\n";
    if (this->_args.size() < 2){
        qDebug() << "Need 2 arguments\n";
        return;
    }
    int cpt = 0;
    bool validPath = true;
    QList<QByteArray> listArgs = _args[1].split('/');
    Folder* fo = user->currentFolder();

    while (validPath && cpt < listArgs.size()){
        if (listArgs[cpt] == ".."){
            if (fo->getParent() == nullptr)
                validPath = false;
            else
                fo = fo->getParent();
        }

        else {
            if (validPath){
                for (Folder *child : fo->children()){
                    if (child->getName() == QString(listArgs[cpt])) {
                        fo = child;
                        qDebug() << fo->getName();
                    }
                }
                if (fo == user->currentFolder()){
                    validPath = false;
                    qDebug() << "Bad path argument\n";
                }
            }
        }
        cpt++;
    }

    if (validPath){
        for (File *fi : user->currentFolder()->files()){
            if (fi->getName() == QString(this->_args[0])){
                fo->addFile(fi);
                user->currentFolder()->removeFile(fi);
            }
        }
    }
}
