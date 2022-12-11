#include "deposidcahs.h"
#include "ui_deposidcahs.h"
#include "welcomeWindow.h"

DeposidCahs::DeposidCahs(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DeposidCahs)
{
    ui->setupUi(this);
    timer = new QTimer( this );
    connect( timer, SIGNAL(timeout()), this, SLOT(TimerEnd()));
    timer->start( 30000 ); // 2 seconds single-shot timer
}

DeposidCahs::~DeposidCahs()
{
    delete ui;
}

void DeposidCahs::on_withd20_clicked()
{
    createEvent("20");

}


void DeposidCahs::on_withd40_clicked()
{
    createEvent("40");

}


void DeposidCahs::on_withd50_clicked()
{
    createEvent("50");

}


void DeposidCahs::on_withd100_clicked()
{
    createEvent("100");
}


void DeposidCahs::on_pushButton_5_clicked()
{
    userHomePage *uspag = new userHomePage();
    uspag->show();
    this->close();

}


void DeposidCahs::on_inputWith_editingFinished()
{

}


void DeposidCahs::on_inputPressed_clicked()
{
    createEvent(ui->inputWith->text());
}

void DeposidCahs::createEvent(QString num)
{
    QDateTime dateTime = dateTime.currentDateTime();

    QJsonObject jsonObj;
    jsonObj.insert("account_id",userdata::getAccountId());
    jsonObj.insert("card_id",userdata::getCardId());
    jsonObj.insert("date",dateTime.toString("yyyy-MM-dd HH:mm:ss"));
    jsonObj.insert("action","cash withdrawal");
    jsonObj.insert("sum",num);


    QString site_url=MyUrl::getBaseUrl()+"/event";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(userdata::getWebToken()));
    //WEBTOKEN LOPPU

    postManager = new QNetworkAccessManager(this);
    connect(postManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(addEvent(QNetworkReply*)));

    reply = postManager->post(request, QJsonDocument(jsonObj).toJson());
}
/*
void DeposidCahs::SetUserPage(userHomePage onj)
{
    objHomePage = onj;
}*/

void DeposidCahs::addEvent(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    reply->deleteLater();
    postManager->deleteLater();
    //objHomePage->startSetUp();
}

void DeposidCahs::TimerEnd()
{
    if(this->isVisible())
    {    userdata::cardId="";
        userdata::cardType="";
        userdata::accountId="";
        userdata::balance=0;
        userdata::credit_limit=0;
        userdata::webToken="";



        welcomeWindow *w = new welcomeWindow;
        w->show();
        this->close();}

}

