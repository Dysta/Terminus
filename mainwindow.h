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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;

private slots:
    void onBlockCountChanged(int newBlockCount);
    void onButtonClic(bool);

private:
    void createTerminal(QString title);

    Ui::MainWindow *ui;

    QWidget* _mainWidget;
    QGridLayout* _grid;
    QKeyEvent* _keyPress;
    QKeyEvent* _keyRelease;

    QGroupBox* _terminalBox;
    QPlainTextEdit* _terminal;
    QLineEdit* _terminalInput;

    const QString _html = "<b><span style='color:green'>Jarvis@u-bdx</span>: <span style='color:blue'>~</span>$ </b>";
    bool _edit;

};

#endif // MAINWINDOW_H
