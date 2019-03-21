#include "console.h"
#include <QDebug>

Console::Console(QWidget* parent)
    : QPlainTextEdit(parent)
{
    QPalette p = palette();
    p.setColor(QPalette::Base, Qt::black);
    p.setColor(QPalette::Text, Qt::green);
    this->setPalette(p);
}

void Console::keyPressEvent(QKeyEvent *e) {
    switch (e->key()) {
        case Qt::Key_Return:
        case Qt::Key_Enter:
            std::cout << "enter key pressed" << std::endl;
            // appel a parserInput
            break;
        case Qt::Key_Backspace:
            std::cout << "suppr key" << std::endl;
            this->_buffer = this->_buffer.left(this->_buffer.size() - 1);
            break;
        default:
            std::cout << "key pressed" << std::endl;
            std::cout << e->text().toStdString() << std::endl;
            QByteArray key(e->text().toStdString().c_str());
            this->_buffer.append(key);
            break;
    }

    qDebug() << this->_buffer;
}
