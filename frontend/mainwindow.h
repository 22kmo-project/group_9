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
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QTimer *timer;
    void CreditWindowCheck();
private slots:

    void on_loginB_clicked();
    void loginSlot (QNetworkReply *reply);


    void MyTimerEnd();
    void CreditChekSlot(QNetworkReply *reply);


    void on_cardNumEnter_editingFinished();

private:
    Ui::MainWindow *ui;
    userHomePage *objectUserHomePage;
    CardTypeWIndow *objectCardType;
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QByteArray response_data;
    QString id_card;
    QString pin;


    QNetworkAccessManager *gradeManager;

};
#endif // MAINWINDOW_H
