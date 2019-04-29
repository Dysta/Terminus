#include "ls.h"
#include "console.h"

Ls::Ls()
    : Command(){}

Ls::Ls(QList<QByteArray> args)
    : Command(args) {}

void Ls::command_effect(Console* console, User* user){

    QString answer, color;

    qDebug() << "Commande LS lancée !\n";
    qDebug() << "Dossiers : \n";
    for (Folder* child : user->currentFolder()->children()){
        qDebug() << child->getName();
        answer.append("<span style='color:" + Color::cyan + "'>" + child->getName() + "/   </span>");
    }
    qDebug() << "Fichiers : \n";
    for (File* child : user->currentFolder()->files()){
        qDebug() << child->getName() << ", " << child->getContent();
        color = getColorMode(child->getMode());
        answer.append("<span style='color:" + color + "'>" + child->getName() + "   </span>");
    }

    console->appendHtml(answer);
}

QString Ls::getColorMode(int mode) {
    switch (mode) {
    case File::Mode::RD_ONLY:
        return Color::white;
    case File::Mode::WR_ONLY:
        return Color::white;
    case File::Mode::EX_ONLY:
        return Color::green;
    case File::Mode::RW:
        return Color::white;
    case File::Mode::XRW:
        return Color::apple;
    default:
        return Color::white;
    }
}
