#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>

#include <QString>
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
    const QString _html = "<b><span style='color:green'>Jarvis@u-bdx</span>: <span style='color:blue'>~</span>$ </b>";

    int _shift;
};

#endif // CONSOLE_H
