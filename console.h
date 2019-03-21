#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>

#include <QWidget>
#include <QPlainTextEdit>
#include <QByteArray>
#include <QPalette>


class Console : public QPlainTextEdit
{
public:
    Console(QWidget* parent = nullptr);


protected:
    void keyPressEvent(QKeyEvent *e) override;

private:
    QByteArray _buffer;

};

#endif // CONSOLE_H
