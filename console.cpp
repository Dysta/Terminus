#include "console.h"

Console::Console(QWidget* parent)
    : QPlainTextEdit(parent), _cursorPosition(0)
{
    QPalette p = palette();
    p.setColor(QPalette::Base, Qt::black);
    p.setColor(QPalette::Text, Qt::green);
    this->setPalette(p);
}

void Console::keyPressEvent(QKeyEvent *e) {

    // permet de garder les event du QPlainTextEdit (comme déplacement du curseur et autre)
    QPlainTextEdit::keyPressEvent(e);

    switch (e->key()) {

    case Qt::Key_Backspace:
        std::cout << "delete key pressed" << std::endl;
        if (this->_buffer.size() > 0 && this->_cursorPosition > 0) {
            this->_buffer = this->_buffer.remove(this->_cursorPosition - 1, 1);
            this->_cursorPosition--;
        }
        break;
    case Qt::Key_Delete:
        std::cout << "suppr key pressed" << std::endl;
        if (this->_buffer.size() > 0) {
            this->_buffer = this->_buffer.remove(this->_cursorPosition, 1);
        }
        break;
    case Qt::Key_Left:
        std::cout << "left arrow key pressed" << std::endl;
        if (this->_cursorPosition > 0) this->_cursorPosition--;
        break;
    case Qt::Key_Right:
        std::cout << "right arrow key pressed" << std::endl;
        if (this->_cursorPosition < this->_buffer.size()) this->_cursorPosition++;
        break;
    case Qt::Key_Return:
    case Qt::Key_Enter:
        std::cout << "enter key pressed" << std::endl;
        // appel a parserInputrr
        this->_buffer.clear();
        this->_cursorPosition = 0;
        break;
    default:
        std::cout << "any key pressed : " << e->text().toStdString() << std::endl;
        QByteArray key(e->text().toStdString().c_str());
        this->_buffer.insert(this->_cursorPosition, key);
        this->_cursorPosition++;
        break;
    }

    qDebug() << this->_buffer;
    qDebug() << this->_buffer.size();
    qDebug() << this->_cursorPosition;
 }
