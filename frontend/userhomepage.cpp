#include "userhomepage.h"
#include "ui_userhomepage.h"

userHomePage::userHomePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userHomePage)
{
    ui->setupUi(this);
    ui->lableIdOwner->setText(userdata::getCardId());
    idCard=userdata::getCardId();
    startSetUp();

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


}

void userHomePage::setEventsInView(QNetworkReply *reply)
{
    qDebug()<<"setEventsInView" ;

    QByteArray response_data=reply->readAll();
      QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
      QJsonArray json_array = json_doc.array();
      foreach (const QJsonValue &value, json_array) {
          QJsonObject json_obj = value.toObject();
          QString grade="event date: "+json_obj["dateeu"].toString()+" , action: " + json_obj["action"].toString()+ ", sum: " +QString::number(json_obj["sum"].toInt())+" , account id: "+
                            QString::number(json_obj["account_id"].toInt())+"  "+json_obj["grade_date"].toString()+"\r\n";

          ui->bankView->addItem(grade);

          qDebug()<<"setEventsInView" + grade;

      }

        reply->deleteLater();
      gradeManager->deleteLater();
}

void userHomePage::startSetUp()
{
    qDebug()<<"startSetUp, webToken: " + userdata::getWebToken();

    QString site_url=MyUrl::getBaseUrl()+"/event";
        QNetworkRequest request((site_url));
        //WEBTOKEN ALKU
        request.setRawHeader(QByteArray("Authorization"),(userdata::getWebToken()));
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
    request.setRawHeader(QByteArray("Authorization"),(userdata::getWebToken()));
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
       book+="card type: " +json_obj["card_type"].toString()+" , balance: "+QString::number(json_obj["balance"].toInt())+" , credit limit: "+
                      QString::number(json_obj["credit_limit"].toInt())+" , account owner: "+json_obj["fname"].toString()+"\r\n";
    }

    qDebug()<<book;
    ui->cardInfo->setText(book);


    reply->deleteLater();
    gradeManager->deleteLater();
}


void userHomePage::on_pushButton_2_clicked()
{
    objectEvent = new EventWindow();
    objectEvent->show();
}

