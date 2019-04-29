#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QProgressBar>
#include <QLabel>

#include <iostream>

#include "commands/command.h"
#include "console.h"
#include "folder.h"
#include "file.h"
#include "user.h"
#include "color.h"

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
    void createPictureBox(const QString& title);
    void createTree(void);
    void launchCommand();

    Ui::MainWindow *ui;

    QWidget* _mainWidget;
    QGridLayout* _grid;
    QString _html = "<b><span style='color:" + Color::green + "'>Jarvis@u-bdx</span>: <span style='color:" + Color::cyan + "'>~</span> $</b> ";

    Console* _console;
    Command* _cmd;

    QGroupBox* _missionBox;
    QGroupBox* _pictureBox;

    Folder* _tree;

    User* _user;

};

#endif // MAINWINDOW_H
