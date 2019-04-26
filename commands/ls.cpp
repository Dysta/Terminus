#include "ls.h"


Ls::Ls()
    : Command(){}

Ls::Ls(QList<QByteArray> args)
    : Command(args) {}

void Ls::command_effect(User* user, Folder *f){
    Q_UNUSED(user);
    qDebug() << "Commande LS lancée !\n";
    qDebug() << "Dossiers : \n";
    for (int i = 0; i < f->children().size(); i++){
        qDebug() << f->children().at(i)->getName() << "\n";
    }
    qDebug() << "Fichiers : \n";
    for (int i = 0; i < f->files().size(); i++){
        qDebug() << f->files().at(i)->getName() << ", " << f->files().at(i)->getContent() << "\n";
    }
}
