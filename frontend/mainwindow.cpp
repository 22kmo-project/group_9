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

                qDebug()<<"getCardId: " + userdata::getCardId();
                qDebug()<<"webToken: " + userdata::getWebToken();



                CreditWindowCheck();

            }
        }
    }

}




void MainWindow::on_cardNumEnter_editingFinished()
{
       timer = new QTimer( this );
       connect( timer, SIGNAL(timeout()), this, SLOT(MyTimerEnd()));
       timer->start( 10000 ); // 2 seconds single-shot timer
}


void MainWindow::MyTimerEnd()
{
    qDebug() << "Timer end";
    ui->cardNumEnter->clear();
    ui->pinEnter->clear();
    ui->errorTxt->setText("10 seconds gone");

}

void MainWindow::CreditWindowCheck()
{

    qDebug()<<"startSetUp, webToken: " + userdata::getWebToken();

    QString site_url=MyUrl::getBaseUrl()+"/card/"+userdata::cardId;
        QNetworkRequest request((site_url));
        //WEBTOKEN ALKU
        request.setRawHeader(QByteArray("Authorization"),(userdata::getWebToken()));
        //WEBTOKEN LOPPU
        gradeManager = new QNetworkAccessManager(this);

        connect(gradeManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(CreditChekSlot(QNetworkReply*)));

        reply = gradeManager->get(request);

}

void MainWindow::CreditChekSlot(QNetworkReply *reply)
{


    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString book = "";
    QString account_id = "";
    qDebug()<<response_data;

    foreach (const QJsonValue &value, json_array) {
       QJsonObject json_obj = value.toObject();
       book+=json_obj["card_type"].toString();

       account_id+=QString::number(json_obj["account_id"].toInt());
       userdata::accountId =QString::number(json_obj["account_id"].toInt());
       userdata::cardType = book;


    }

    if(book=="credit"){
        objectCardType = new CardTypeWIndow();
        objectCardType->show();
    }else{
        objectUserHomePage=new userHomePage();
            objectUserHomePage->show();
    }

qDebug()<<"id Account " + userdata::accountId;
qDebug()<<"cardType " + userdata::cardType;



    /*objectUserHomePage=new userHomePage(id_card);
    objectUserHomePage->setWebToken("Bearer "+response_data);
    objectUserHomePage->show();*/
     this->close();
}

