#include "console.h"
#include <QDebug>

Console::Console(QWidget* parent)
    : QPlainTextEdit(parent), _shift(0)
{
    QPalette p = palette();
    p.setColor(QPalette::Base, Qt::black);
    p.setColor(QPalette::Text, Qt::green);
    this->setPalette(p);
}

void Console::keyPressEvent(QKeyEvent *e) {

    QPlainTextEdit::keyPressEvent(e);

    switch (e->key()) {

    case Qt::Key_Backspace:
        std::cout << "suppr key" << std::endl;
        if (this->_buffer.size() > 0) {
                this->_buffer = this->_buffer.remove(this->_shift - 1, 1);
        }
        if (this->_shift > 0) this->_shift--;
        break;
    case Qt::Key_Left:
        if (this->_shift > 0) this->_shift--;
        break;
    case Qt::Key_Right:
        if (this->_shift < this->_buffer.size()) this->_shift++;
        break;
    case Qt::Key_Return:
    case Qt::Key_Enter:
        std::cout << "enter key pressed" << std::endl;
        // appel a parserInputrr
        this->_buffer.clear();
        this->_shift = 0;
        break;
    default:
        std::cout << "key pressed : " << e->text().toStdString() << std::endl;
        QByteArray key(e->text().toStdString().c_str());
        this->_buffer.insert(this->_shift, key);
        this->_shift++;
        break;
    }

    qDebug() << this->_buffer;
    qDebug() << "shift : " << this->_shift;
    qDebug() << "buff size : " << this->_buffer.size();
 }
