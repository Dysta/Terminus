#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>

#include <QString>
#include <QPlainTextEdit>
#include <QByteArray>
#include <QPalette>

#include <QDebug>

#include "inputparser.h"

class Console : public QPlainTextEdit
{
    Q_OBJECT

public:
    Console(QWidget* parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *e) override;
    void mousePressEvent(QMouseEvent *e) override;
    void mouseDoubleClickEvent(QMouseEvent *e) override;

    QByteArray _buffer;
    const QString _html = "\r<b><span style='color:green'>Jarvis@u-bdx</span>: <span style='color:blue'>~</span>$ </b>";

    InputParser* _parser;

    int _cursorPos;
};

#endif // CONSOLE_H
