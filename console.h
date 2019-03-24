#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>

#include <QString>
#include <QPlainTextEdit>
#include <QByteArray>
#include <QPalette>

#include <QDebug>

#define MAX_COLUMN 100


class Console : public QPlainTextEdit
{
    Q_OBJECT

public:
    Console(QWidget* parent = nullptr);

protected slots:
    void onCursorPositionChange(void);
    void onNewLine(int newLine);

protected:
    void keyPressEvent(QKeyEvent *e) override;

    QByteArray _buffer;
    const QString _html = "<b><span style='color:green'>Jarvis@u-bdx</span>: <span style='color:blue'>~</span>$ </b>";

    int _currentColumn;
    int _currentLine;
    int _lastLine;
};

#endif // CONSOLE_H
