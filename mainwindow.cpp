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
    this->_keyPress = new QKeyEvent(QEvent::KeyPress, Qt::Key_Enter, Qt::NoModifier);
    this->_keyRelease = new QKeyEvent(QEvent::KeyRelease, Qt::Key_Enter, Qt::NoModifier);

    this->createTerminal("Terminal");

    this->_mainWidget->setLayout(this->_grid);
    this->setCentralWidget(this->_mainWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createTerminal(QString title) {
    this->_terminalBox = new QGroupBox(title);
    this->_terminal = new QPlainTextEdit(this->_terminalBox);
    this->_terminalInput = new QLineEdit(this->_terminalBox);

    //this->_terminal->appendHtml(this->_html);
    this->_terminal->setStyleSheet("background-color:black; color: white;");
    this->_terminalInput->setText(this->_html);
    this->_terminalInput->setStyleSheet("background-color:black; color: white;");

    this->_terminalInput->keyPressEvent(this->_keyPress);
    this->_terminalInput->keyReleaseEvent(this->_keyRelease);

    connect(this->_terminal, SIGNAL(blockCountChanged(int)),
            this, SLOT(onBlockCountChanged(int)));

    this->_grid->addWidget(this->_terminalBox, 0, 0);
}

void MainWindow::onBlockCountChanged(int newBlockCount) {
    this->_edit = !this->_edit;
    if (this->_edit) {
        std::cout << "new count" << newBlockCount << std::endl;
        //this->_terminal->clear();
        this->_terminal->appendHtml(this->_html);
        std::cout << "end" << std::endl;
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Enter) {
        std::cout << "enter key pressed" << std::endl;
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *event) {
    std::cout << "key released" << std::endl;
}

void MainWindow::onButtonClic(bool) {
    std::cout << "button enter pressed" << std::endl;
    QString input = this->_terminalInput->text();
    std::cout << "input = " << input.toStdString() << std::endl;
    this->_terminal->appendHtml(input);
    this->_terminalInput->clear();
}


