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

