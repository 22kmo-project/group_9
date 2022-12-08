#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <userhomepage.h>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <cardtypewindow.h>
#include "myurl.h"
#include "userdata.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_loginB_clicked();
    void loginSlot (QNetworkReply *reply);



private:
    Ui::MainWindow *ui;
    //userHomePage *objectUserHomePage;
    CardTypeWIndow *objectCardType;
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString id_card;
    QString pin;
};
#endif // MAINWINDOW_H
