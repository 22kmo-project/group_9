#include "eventwindow.h"
#include "ui_eventwindow.h"

EventWindow::EventWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EventWindow)
{
    ui->setupUi(this);
}

EventWindow::~EventWindow()
{
    delete ui;
}

void EventWindow::addEvent(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    reply->deleteLater();
    postManager->deleteLater();
}

void EventWindow::on_eventB_clicked()
{
    QJsonObject jsonObj;
    jsonObj.insert("account_id","1");
    jsonObj.insert("card_id","1");
    jsonObj.insert("date","2022-12-8");
    jsonObj.insert("action","qt App");
    jsonObj.insert("sum","150");


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

