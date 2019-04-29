#include "cat.h"
#include "console.h"

Cat::Cat()
{

}

Cat::Cat(QList<QByteArray> args)
    : Command(args) {}

void Cat::command_effect(Console *console, User *user) {

    if (this->_args.isEmpty()) {
        console->appendHtml("Aucun fichier ou dossier de ce type");
        return;
    }

    for (File* f : user->currentFolder()->files()) {
        if (f->getName() == this->_args.first()) {
            console->appendHtml("<span style='color:" + Color::white + "'>" + f->getContent() + "   </span>");
            return;
        }
    }

    for (Folder* f : user->currentFolder()->children()) {
        if (f->getName() == this->_args.first()) {
            console->appendHtml("<span style='color:" + Color::red + "'>" + f->getName() + " est un dossier</span>");
            return;
        }
    }

    console->appendHtml("Aucun fichier ou dossier de ce type");
}
