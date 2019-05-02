#include "console.h"
#include "mainwindow.h"

Console::Console(QWidget* parent)
    : QPlainTextEdit(parent), _cursorPos(0), _ctrlPressed(false)
{
    this->_mw = qobject_cast<MainWindow*>(parent);
    QPalette p = palette();
    p.setColor(QPalette::Base, Qt::black);
    p.setColor(QPalette::Text, Qt::green);
    this->setPalette(p);

    this->_buffer.append(this->_mw->html());
    this->appendHtml(this->_buffer);

    this->_parser = new InputParser();
}

// override function for disable mouse click event
void Console::mousePressEvent(QMouseEvent *e) {
    Q_UNUSED(e);
}

// override function for disable mouse double click event
void Console::mouseDoubleClickEvent(QMouseEvent *e) {
    Q_UNUSED(e);
}

void Console::keyReleaseEvent(QKeyEvent *e) {
    switch (e->key()) {
    case Qt::Key_Control:
        this->_ctrlPressed = false;
        std::cout << "ctrl released" << std::endl;
        break;
    default:
        break;
    }
}

void Console::keyPressEvent(QKeyEvent *e) {
    qDebug() << "key : " << e->text();

    if (
            e->matches(QKeySequence::SelectAll) ||
            e->matches(QKeySequence::DeleteEndOfWord) ||
            e->matches(QKeySequence::DeleteStartOfWord) ||
            e->matches(QKeySequence::Undo)
        )
        return;

    switch (e->key()) {

    case Qt::Key_Control:
        this->_ctrlPressed = true;
        std::cout << "ctrl pressed" << std::endl;
        break;

    case Qt::Key_Left:
        if (this->_cursorPos > 0){
            this->_cursorPos--;
            QPlainTextEdit::keyPressEvent(e);
        }
        break;

    case Qt::Key_Right:
        if (this->_cursorPos < this->_buffer.size() - this->_mw->html().size() ) this->_cursorPos++;
        QPlainTextEdit::keyPressEvent(e);
        break;

    case Qt::Key_Up:
        if (this->_historic.isEmpty() || this->_historic.isNull()) return;
        if (this->_buffer == this->_historic) return;
        this->_buffer = this->_historic;
        this->appendHtml(this->_buffer);
        this->_cursorPos = this->_buffer.size() - this->_mw->html().size();
        break;

    case Qt::Key_Down:
        if (this->_historic.isEmpty() || this->_historic.isNull()) return;
        if (this->_buffer == this->_mw->html()) return;
        this->_buffer.clear();
        this->_buffer.append(this->_mw->html());
        this->_cursorPos = 0;
        this->appendHtml(this->_buffer);
//        this->_cursorPos = this->_buffer.size();
        break;

    case Qt::Key_Backspace:
        if (this->_buffer != this->_mw->html() && this->_cursorPos > 0) {
            this->_buffer.chop(1);
            //this->_buffer = this->_buffer.remove(this->_cursorPos, 1);
            this->_cursorPos--;
            QPlainTextEdit::keyPressEvent(e);
        }
        break;

    case Qt::Key_Delete:
        if (this->_buffer.size() > 0) {
            this->_buffer = this->_buffer.remove(this->_cursorPos, 1);
            QPlainTextEdit::keyPressEvent(e);
        }
        break;

    case Qt::Key_Return:
    case Qt::Key_Enter:
        if (this->_buffer != this->_mw->html()) {
            this->_parser->parse(this->_buffer, this->_mw->html().size());
            this->_mw->setCmd(this->_parser->getCommand());
            this->_historic = this->_buffer;
            this->_buffer.clear();
            this->_cursorPos = 0;
            this->_buffer.append(this->_mw->html());
            this->appendHtml(this->_buffer);
        }
        break;

    default:
        if (this->_ctrlPressed){
            if(e->key() == Qt::Key_L){
                this->clear();
                this->_buffer.clear();
                this->_cursorPos = 0;
                this->_buffer.append(this->_mw->html());
                this->appendHtml(this->_buffer);
            }
            return;
        }
        QByteArray key(e->text().toStdString().c_str());
        if(e->key() > 16000000) break;

        this->_buffer.insert(this->_cursorPos + this->_mw->html().length(), key);
        this->_cursorPos++;
        QPlainTextEdit::keyPressEvent(e);
        break;

    }

    qDebug() << "current buffer :" << this->_buffer;
    qDebug() << "buffer size: " << this->_buffer.size();
    qDebug() << "current cursor pos: " << this->_cursorPos;
    qDebug() << "historic :" << this->_historic;
}
