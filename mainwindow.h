#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QGroupBox>

#include <iostream>

#include "commands/command.h"
#include "console.h"
#include "folder.h"
#include "file.h"
#include "user.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setCmd(Command *cmd);

    QString html() const;

private:
    void createTerminal();
    void createMissionBox(const QString& title);
    void createBox(const QString& title);
    void createTree(void);

    Ui::MainWindow *ui;

    QWidget* _mainWidget;
    QGridLayout* _grid;
    QString _html = "<b><span style='color:green'>Jarvis@u-bdx</span>: <span style='color:blue'>~</span> $</b> ";

    Console* _console;
    Command* _cmd;

    QGroupBox* _missionBox;
    QGroupBox* _box;

    Folder* _tree;

    User* _user;

};

#endif // MAINWINDOW_H
