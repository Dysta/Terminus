#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QGroupBox>
#include <QPlainTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QEvent>
#include <QKeyEvent>

#include <QString>

#include <iostream>

#include "console.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void createTerminal(QString title);

    Ui::MainWindow *ui;

    QWidget* _mainWidget;
    QGridLayout* _grid;
    QKeyEvent* _keyPress;
    QKeyEvent* _keyRelease;

    QGroupBox* _terminalBox;
    Console* _console;


    const QString _html = "<b><span style='color:green'>Jarvis@u-bdx</span>: <span style='color:blue'>~</span>$ </b>";
    bool _edit;

};

#endif // MAINWINDOW_H
