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
        {"cadernis", &Man::man_cadernis}
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
    console->appendHtml("man man");
}

void Man::man_cd(Console* console) {
    console->appendHtml("man cd");
}

void Man::man_echo(Console* console) {
    console->appendHtml("man echo");
}

void Man::man_cat(Console *console) {
    console->appendHtml("man cat");
}

void Man::man_cadernis(Console *console) {
    console->appendHtml("coucou :)");
}
