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
    //delete objectUserHomePage;
    //objectUserHomePage=nullptr;
}


void MainWindow::on_loginB_clicked()
{
    id_card =ui->cardNumEnter->text();
    pin =ui->pinEnter->text();

    QJsonObject jsonObj;
    jsonObj.insert("id_card",id_card);
    jsonObj.insert("pin",pin);

    QString site_url = MyUrl::getBaseUrl()+"/login";
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
    int test =QString::compare(response_data,"false");
    qDebug()<<test;

    if(response_data.length()==0){
        ui->errorTxt->setText("host not working");

    }
    else{
        if(QString::compare(response_data,"-4078")==0){
            ui->errorTxt->setText("problem in database");

        }else{
            if(test == 0){
                ui->cardNumEnter->clear();
                ui->pinEnter->clear();
                ui->errorTxt->setText("card num or pin is wrong!");
            }else{
                userdata::cardId = id_card;
                userdata::webToken = "Bearer "+response_data;

                objectCardType = new CardTypeWIndow();
                objectCardType->show();

                /*objectUserHomePage=new userHomePage(id_card);
                objectUserHomePage->setWebToken("Bearer "+response_data);
                objectUserHomePage->show();*/


                qDebug()<<"getCardId: " + userdata::getCardId();
                qDebug()<<"webToken: " + userdata::getWebToken();

                this->close();

            }
        }
    }

}



