#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_findButton_clicked()
{
    QString searchString = ui->lineEdit->text();
    /*QMessageBox *msgBox = new QMessageBox(this);
    msgBox->setText(searchString);
    msgBox->show();*/

    QString buildUrl = "http://www.dict.org/bin/Dict?Form=Dict1&Query=" + searchString + "&Strategy=*&Database=*";//"http://dict.cn/mini.php?q=" + searchString;
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);

    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply *)));


    manager->get(QNetworkRequest(QUrl(buildUrl)));


    /*QString html = response->readAll();

    ui->plainTextEdit->clear();
    ui->plainTextEdit->appendHtml(html);*/
}


QString MainWindow::downloadHtml()
{
    //@example: QNetworkAccessManager example on how to download html to qstring
    QString result ="";
    QNetworkAccessManager *manager = new QNetworkAccessManager();

    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply *)));

    return result;
}

void MainWindow::replyFinished(QNetworkReply* reply)
{
   QString result =   reply->readAll();

   ui->plainTextEdit->clear();
   ui->plainTextEdit->appendHtml(result);

}
