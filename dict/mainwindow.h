#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QtNetwork>

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
    void on_findButton_clicked();
    void replyFinished(QNetworkReply* replyFinished);

private:
    Ui::MainWindow *ui;
    QString downloadHtml();

};

#endif // MAINWINDOW_H
