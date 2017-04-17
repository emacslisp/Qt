#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    ui->path1->setText("C:\\");

    //@todo: load file into textbox
    QDir myDir("C:\\");

    QStringList filter("*");
    QStringList filesList = myDir.entryList(QStringList(filter),QDir::Files | QDir::Dirs);
    model.setStringList(filesList);
    ui->listView->setModel(&model);
}

MainWindow::~MainWindow()
{
    delete ui;
}
