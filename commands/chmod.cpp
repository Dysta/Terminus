#include "chmod.h"
#include "console.h"

Chmod::Chmod()
{

}

Chmod::Chmod(QList<QByteArray> args)
    : Command(args) {}


void Chmod::command_effect(Console *console, User *user) {
    if (this->_args.isEmpty()) return;
    // args are like "flags (+-xwr)" "filename"
    QByteArray flag(this->_args.first());
    QByteArray filename(this->_args.last());

    File* file = this->getFileByname(user->currentFolder(), filename);
    if (file == nullptr) {
        console->appendHtml("Fichier introuvable ou inexistant");
        return;
    }

    if (flag[0] == '+' || flag[0] == '-') {
        if (flag[1]) {
            switch (flag[1]) {
            case 'x':
                file->setMode(File::Mode::EX_ONLY);
                break;
            case 'r':
                file->setMode(File::Mode::RD_ONLY);
                break;
            case 'w':
                file->setMode(File::Mode::WR_ONLY);
                break;
            default:
                console->appendHtml("Argument invalide : " + flag);
                return;
            }
        } else {
            console->appendHtml("Argument invalide : " + flag);
            return;
        }
    } else {
        console->appendHtml("Argument invalide : " + flag);
        return;
    }
}

File* Chmod::getFileByname(const Folder* folder, const QByteArray &name) {
    QString strName(name);
    for (File* f : folder->files()) {
        if (f->getName() == strName)
            return f;
    }
    return nullptr;
}
