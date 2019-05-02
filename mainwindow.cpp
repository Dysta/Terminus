#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Terminus 2k19");
    this->setMinimumSize(QSize(1000, 600));

    this->_mainWidget = new QWidget(this);
    this->_grid = new QGridLayout();
    this->_user = new User();

    this->askName();
    this->createTree();
    this->createTerminal();
    this->createMissionBox("Missions");
    this->createPictureBox("Lieu");

    this->_mainWidget->setLayout(this->_grid);
    this->setCentralWidget(this->_mainWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::askName() {
    QString name = QInputDialog::getText(this, "Choisir nom", "nom");
    if (!name.isEmpty()){
        this->_user->setName(name);
        qDebug() << "USER NAME : " << _user->name();
        this->_html.replace(QRegExp(">[A-Za-z]*@"), ">" + this->_user->name() + "@");
    }
}

void MainWindow::createTerminal() {
    this->_console = new Console(this);
    this->_console->setGeometry(0, 0, this->width() / 2, this->height());
    this->_grid->addWidget(this->_console, 0, 0, 2, 1);
}

void MainWindow::createMissionBox(const QString &title) {
    this->_missionBox = new QGroupBox(title, this);
    this->_missionBox->setMinimumSize(QSize(400, 250));
    this->_grid->addWidget(this->_missionBox, 0, 1);
}

void MainWindow::createPictureBox(const QString &title) {
    this->_pictureBox = new QGroupBox(title, this);
    this->_pictureBox->setMinimumSize(QSize(400, 250));
    this->_grid->addWidget(this->_pictureBox, 1, 1);
}

void MainWindow::createTree() {
    this->_tree = new Folder("home");
    Folder *f1 = new Folder("room_1", this->_tree);
    Folder *f2 = new Folder("room_2", f1);
    Folder *f3 = new Folder("room_3", f1);
    Folder *f4 = new Folder("room_4", f2);
    this->_tree->addChild(f1);
    this->_tree->setParent(nullptr);
    f1->addChild(f3);
    f1->addChild(f2);
    f2->addChild(f4);

    File *fi1 = new File("file1", "fichier de la room_1", File::Mode::EX_ONLY);
    File *fi2 = new File("file2", "fichier de la room_2", File::Mode::RD_ONLY);
    File *fi3 = new File("file3", "fichier de la room_3", File::Mode::XRW);
    File *fi4 = new File("file4", "fichier de la room_4", File::Mode::RW);
    f1->addFile(fi1);
    f1->addFile(fi2);
    f1->addFile(fi3);
    f1->addFile(fi4);
    this->_user->setCurrentFolder(this->_tree);
    this->_html.replace("~", this->_user->currentFolder()->getName());
}

QString MainWindow::html() const
{
    return _html;
}

void MainWindow::setCmd(Command *cmd)
{
    _cmd = cmd;
    this->launchCommand();
}

void MainWindow::launchCommand() {
    if (_cmd == nullptr) return;
    _cmd->command_effect(this->_console, this->_user);
    this->_html.replace(QRegExp(">[a-z0-9~_]{1,}<"), ">" + this->_user->currentFolder()->getName() + "<");
    delete _cmd;
}


