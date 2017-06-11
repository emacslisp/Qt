#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    QString path=".";
#if defined Q_OS_WIN
    path = "C:\\";
#elif defined Q_OS_MACOS
    path = "/";
#else
#error "We don't support that version yet..."
#endif

    ui->path1->setText(path);

    //@todo: load file into textbox
    //detect whether is mac or not
    QDir myDir(path);

    QStringList filter("*");
    QStringList filesList = myDir.entryList(QStringList(filter),QDir::Files | QDir::Dirs);
    model.setStringList(filesList);
    ui->listView->setModel(&model);
}

MainWindow::~MainWindow()
{
    delete ui;
}
