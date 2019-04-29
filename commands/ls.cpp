#include "ls.h"
#include "console.h"

Ls::Ls()
    : Command(){}

Ls::Ls(QList<QByteArray> args)
    : Command(args) {}

void Ls::command_effect(Console* console, User* user, Folder *f){
    Q_UNUSED(user);

    QString answer;

    qDebug() << "Commande LS lancée !\n";
    qDebug() << "Dossiers : \n";
    for (Folder* child : f->children()){
        qDebug() << child->getName();
        answer.append("<span style='color:cyan'>" + child->getName() + "</span>\t");
    }
    qDebug() << "Fichiers : \n";
    for (File* child : f->files()){
        qDebug() << child->getName() << ", " << child->getContent();
        answer.append(child->getName() + "\t");
    }

    console->appendHtml(answer);
}
