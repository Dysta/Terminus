#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _edit(false)
{
    ui->setupUi(this);
    this->setWindowTitle("Terminus 2k29");

    this->_mainWidget = new QWidget(this);
    this->_grid = new QGridLayout(this->_mainWidget);

    this->createTerminal("Terminal");

    this->_mainWidget->setLayout(this->_grid);
    this->setCentralWidget(this->_mainWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createTerminal(QString title) {
    this->_terminalBox = new QGroupBox(title, this);

    this->_console = new Console(this->_terminalBox);
    this->_console->setGeometry(0, 0, this->width() / 2, this->height());

    this->_grid->addWidget(this->_terminalBox);
}
