#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Terminus 2k19");

    this->_mainWidget = new QWidget(this);
    this->_grid = new QGridLayout(this);

    this->createTerminal();
    this->createMissionBox("Missions");
    this->createBox("Box");

    this->_mainWidget->setLayout(this->_grid);
    this->setCentralWidget(this->_mainWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createTerminal() {
    this->_console = new Console(this);

    this->_grid->addWidget(this->_console, 0, 0, 2, 1);
}

void MainWindow::createMissionBox(const QString &title) {
    this->_missionBox = new QGroupBox(title, this);

    this->_grid->addWidget(this->_missionBox, 0, 1);
}

void MainWindow::createBox(const QString &title) {
    this->_box = new QGroupBox(title, this);

    this->_grid->addWidget(this->_box, 1, 1);
}


