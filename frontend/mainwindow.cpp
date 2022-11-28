#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_loginB_clicked()
{
    id_card =ui->cardNumEnter->text();
    password =ui->pinEnter->text();

    QJsonObject jsonObj;
    jsonObj.insert("id_card",id_card);
    jsonObj.insert("pin",password);

    QString site_url="http://localhost:3000/login";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");


    /*
    //WEBTOKEN ALKU
    QByteArray myToken="Bearer xRstgr...";
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU
*/

    loginManager = new QNetworkAccessManager(this);
    connect(loginManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(loginSlot(QNetworkReply*)));

    reply = loginManager->post(request, QJsonDocument(jsonObj).toJson());


}

void MainWindow::loginSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;


    /*
    if(card_num != "1234"){
        ui->cardNumEnter->setText("");
        ui->pinEnter->setText("");

        ui->errorTxt->setText("card num or pin is wrong!");
    }else{
        objectUserHomePage=new userHomePage(card_num);
        objectUserHomePage->show();
    }*/

}

