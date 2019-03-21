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

    case Qt::Key_Backspace:
        std::cout << "suppr key" << std::endl;
        if (this->_buffer.size() > 0)
            this->_buffer = this->_buffer.left(this->_buffer.size() - 1);
        break;
    case Qt::Key_Return:
    case Qt::Key_Enter:
        std::cout << "enter key pressed" << std::endl;
        // appel a parserInputrr
        this->_buffer.append("\r\n");
        break;
    default:
        std::cout << "key pressed" << std::endl;
        std::cout << e->text().toStdString() << std::endl;
        QByteArray key(e->text().toStdString().c_str());
        this->_buffer.append(key);
        break;
    }
    this->clear();
    this->appendPlainText(QString(this->_buffer));
    qDebug() << this->_buffer;
}
