#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QPushButton>
#include <QGroupBox>

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
    void createTerminal(void);
    void createMissionBox(const QString& title);
    void createBox(const QString& title);

    Ui::MainWindow *ui;

    QWidget* _mainWidget;
    QGridLayout* _grid;

    Console* _console;

    QGroupBox* _missionBox;
    QGroupBox* _box;

};

#endif // MAINWINDOW_H
