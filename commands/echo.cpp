#include "echo.h"
#include "console.h"

Echo::Echo()
{

}

Echo::Echo(QList<QByteArray> args)
    : Command(args) {}

void Echo::command_effect(Console *console, User *user) {
    Q_UNUSED(user);

    QString answer = "<span style='color:" + Color::white + "'>";

    for (QByteArray ba : this->_args) {
        answer.append(ba + " ");
    }

    answer.append("</span>");
    console->appendHtml(answer);
}
