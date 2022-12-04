#include "userhomepage.h"
#include "ui_userhomepage.h"

userHomePage::userHomePage(QString id_card, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userHomePage)
{
    ui->setupUi(this);
    ui->lableIdOwner->setText(id_card);
    idCard=id_card;
}

userHomePage::~userHomePage()
{
    delete ui;
}

void userHomePage::on_lableIdOwner_windowIconChanged(const QIcon &icon)
{

}


void userHomePage::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
    qDebug()<<"Set Token " + webToken;
    startSetUp();


}

void userHomePage::setEventsInView(QNetworkReply *reply)
{
    qDebug()<<"setEventsInView" ;

    QByteArray response_data=reply->readAll();
      QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
      QJsonArray json_array = json_doc.array();
      foreach (const QJsonValue &value, json_array) {
          QJsonObject json_obj = value.toObject();
          QString grade=json_obj["date"].toString()+" , "+QString::number(json_obj["sum"].toInt())+" , "+
                  QString::number(json_obj["account_id"].toInt())+" , "+json_obj["grade_date"].toString()+"\r\n";

          ui->bankView->addItem(grade);

          qDebug()<<"setEventsInView" + grade;

      }

        reply->deleteLater();
      gradeManager->deleteLater();
}

void userHomePage::startSetUp()
{
    qDebug()<<"startSetUp";

    QString site_url=MyUrl::getBaseUrl()+"/event";
        QNetworkRequest request((site_url));
        //WEBTOKEN ALKU
        request.setRawHeader(QByteArray("Authorization"),(webToken));
        //WEBTOKEN LOPPU
        gradeManager = new QNetworkAccessManager(this);

        connect(gradeManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(setEventsInView(QNetworkReply*)));

        reply = gradeManager->get(request);
}




void userHomePage::on_accountB_clicked()
{
    //QString wb=this->getWebToken();
    //qDebug()<<wb;

    QString site_url=MyUrl::getBaseUrl()+"/card/"+idCard;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    //QByteArray myToken="Bearer "+wb;
    request.setRawHeader(QByteArray("Authorization"),(webToken));
    //WEBTOKEN LOPPU
    gradeManager = new QNetworkAccessManager(this);

    connect(gradeManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(getCardSlot(QNetworkReply*)));

    reply = gradeManager->get(request);
}

void userHomePage::getCardSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString book = "";
    foreach (const QJsonValue &value, json_array) {
       QJsonObject json_obj = value.toObject();
       book+=json_obj["card_type"].toString()+" , "+QString::number(json_obj["balance"].toInt())+" , "+
               QString::number(json_obj["credit_limit"].toInt())+" , "+json_obj["fname"].toString()+"\r\n";
    }

    qDebug()<<book;
    ui->cardInfo->setText(book);


    reply->deleteLater();
    gradeManager->deleteLater();
}

