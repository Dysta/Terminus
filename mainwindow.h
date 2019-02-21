#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QGroupBox>
#include <QPlainTextEdit>

#include <QString>

#include <iostream>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onBlockCountChanged(int newBlockCount);

private:
    void createTerminal(QString title);

    bool _change;

    Ui::MainWindow *ui;

    QWidget* _mainWidget;
    QGridLayout* _grid;

    QGroupBox* _terminalBox;
    QPlainTextEdit* _terminal;
};

#endif // MAINWINDOW_H
