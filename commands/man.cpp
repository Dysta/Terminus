#include "man.h"
#include "console.h"

Man::Man()
{

}

Man::Man(QList<QByteArray> args)
    : Command(args) {

}

void Man::command_effect(Console *console, User *user) {
    Q_UNUSED(user);

    static std::map<QByteArray, Func> map = {
        {"man", &Man::man_man},
        {"cd", &Man::man_cd},
        {"echo", &Man::man_echo},
        {"cat", &Man::man_cat},
        {"chmod", &Man::man_chmod},
        {"ls", &Man::man_ls},
        {"mv", &Man::man_mv}
    };

    if (this->_args.isEmpty() || this->_args.first() == "man") {
        man_man(console);
        return;
    }
    QByteArray cmd(this->_args.first());

    if (map.count(cmd) == 0) {
        man_man(console);
        return;
    }

    map[cmd](console);
}

void Man::man_man(Console *console) {
    console->appendHtml("<b>Page d'information pour <u>Man</u></b><br />"
                        "<u>Utilisation :</u><br />"
                        "man <b>paramètre</b><br /><br />"
                        "<u>Paramètre :</u><br />"
                        "cat<br />cd<br />chmod<br />echo<br />ls<br />man<br />mv");
}

void Man::man_cd(Console* console) {
    console->appendHtml("<b>Page d'information pour <u>Cd</u></b><br />"
                        "<u>Utilisation :</u><br />"
                        "cd <b>paramètre</b><br /><br />"
                        "<u>Paramètre :</u><br />"
                        "nom de dossier");
}

void Man::man_echo(Console* console) {
    console->appendHtml("<b>Page d'information pour <u>Echo</u></b><br />"
                        "<u>Utilisation :</u><br />"
                        "echo <b>paramètre</b><br /><br />"
                        "<u>Paramètre :</u><br />"
                        "une phrase/un mot");
}

void Man::man_cat(Console *console) {
    console->appendHtml("<b>Page d'information pour <u>Cat</u></b><br />"
                        "<u>Utilisation :</u><br />"
                        "cat <b>paramètre</b><br /><br />"
                        "<u>Paramètre :</u><br />"
                        "un fichier");
}

void Man::man_chmod(Console *console) {
    console->appendHtml("<b>Page d'information pour <u>Chmod</u></b><br />"
                        "<u>Utilisation :</u><br />"
                        "chmod <b>flag file</b><br /><br />"
                        "<u>Paramètre :</u><br />"
                        "flag : + ou - suivi de x ou w ou r<br />"
                        "file : un nom de fichier");
}

void Man::man_ls(Console *console) {
    console->appendHtml("<b>Page d'information pour <u>Ls</u></b><br />"
                        "<u>Utilisation :</u><br />"
                        "ls<br /><br />"
                        "affiche les dossiers en <span style='color:" + Color::cyan + "'>bleu</span><br />"
                        "affiche les fichiers en <span style='color:" + Color::white + "'>blanc</span> lorsqu'il sont en read/write only<br />"
                        "affiche les fichiers en <span style='color:" + Color::green + "'>vert</span> lorsqu'ils sont executables");
}

void Man::man_mv(Console *console) {
    console->appendHtml("<b>Page d'information pour <u>Mv</u></b><br />"
                        "<u>Utilisation :</u><br />"
                        "mv <b>file folder</b><br /><br />"
                        "<u>Paramètre :</u><br />"
                        "file : un fichier<br />"
                        "folder : un dossier");
}
