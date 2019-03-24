#include "console.h"

Console::Console(QWidget* parent)
    : QPlainTextEdit(parent), _currentColumn(1), _currentLine(1), _lastLine(1)
{
    QPalette p = palette();
    p.setColor(QPalette::Base, Qt::black);
    p.setColor(QPalette::Text, Qt::green);
    this->setPalette(p);

    connect(this, SIGNAL(cursorPositionChanged()),
            this, SLOT(onCursorPositionChange()));
    connect(this, SIGNAL(blockCountChanged(int)),
            this, SLOT(onNewLine(int)));

}

void Console::onCursorPositionChange() {
    QTextCursor tmp = this->textCursor();
    this->_currentColumn = tmp.columnNumber();
    this->_currentLine = tmp.blockNumber();
    qDebug() << "cursor Pos :" << _currentColumn;
    qDebug() << "cursor Line : " << _currentLine;
}

void Console::onNewLine(int newLine) {
    this->_lastLine = newLine;
}

void Console::keyPressEvent(QKeyEvent *e) {
    if ((this->_currentColumn >= MAX_COLUMN || this->_buffer.size() >= MAX_COLUMN )
            && (e->key() != Qt::Key_Backspace && e->key() != Qt::Key_Delete))
        return;

    // permet de garder les event du QPlainTextEdit (comme déplacement du curseur et autre)
    if (e->key() != Qt::Key_Return && e->key() != Qt::Key_Enter)
        QPlainTextEdit::keyPressEvent(e);

    switch (e->key()) {

    case Qt::Key_Backspace:
    case Qt::Key_Delete:
        if (this->_buffer.size() > 0)
            this->_buffer = this->_buffer.remove(this->_currentColumn, 1);
        break;
    case Qt::Key_Return:
    case Qt::Key_Enter:
        // appel a parserInputrr
        this->_buffer.clear();
        break;
    default:
        QByteArray key(e->text().toStdString().c_str());
        if (this->_currentColumn <= 0)
            this->_buffer.insert(0, key);
        else
            this->_buffer.insert(this->_currentColumn - 1, key);
        break;
    }

    qDebug() << this->_buffer;
    qDebug() << "buffer size: " << this->_buffer.size();
    qDebug() << "current cursor pos: " << this->_currentColumn;
    qDebug() << "current cursor line: " << this->_currentLine;
    qDebug() << "last line: " << this->_lastLine;
 }
