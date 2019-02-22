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
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onBlockCountChanged(int newBlockCount);

private:
    void createTerminal(QString title);

    Ui::MainWindow *ui;

    QWidget* _mainWidget;
    QGridLayout* _grid;

    QGroupBox* _terminalBox;
    QPlainTextEdit* _terminal;
    const QString _html = "<b><span style='color:green'>Jarvis@u-bdx</span>: <span style='color:blue'>~</span>$ </b>";
    bool _edit;

};

#endif // MAINWINDOW_H
