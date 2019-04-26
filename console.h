#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>

#include <QString>
#include <QPlainTextEdit>
#include <QByteArray>
#include <QPalette>
#include <QRegExp>

#include <QDebug>

#include "inputparser.h"
#include "folder.h"

class MainWindow;

class Console : public QPlainTextEdit
{
    Q_OBJECT

public:
    Console(QWidget *parent = nullptr);

protected:
    void keyPressEvent(QKeyEvent *e) override;
    void keyReleaseEvent(QKeyEvent *e) override;
    void mousePressEvent(QMouseEvent *e) override;
    void mouseDoubleClickEvent(QMouseEvent *e) override;

    MainWindow* _mw;

    QByteArray _buffer;
    QByteArray _historic;
    const QString _html = "<b><span style='color:green'>Jarvis@u-bdx</span>: <span style='color:blue'>~</span>$</b> ";

    InputParser *_parser;

    QList<Folder *> _folders;
    Folder *_currentFolder;

    int _cursorPos;
    bool _ctrlPressed;
};

#endif // CONSOLE_H
