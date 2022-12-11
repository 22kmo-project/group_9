#include "userhomepage.h"
#include "ui_userhomepage.h"
#include "welcomeWindow.h"
#include "alleventswindow.h"

userHomePage::userHomePage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userHomePage)
{
    ui->setupUi(this);
    ui->lableIdOwner->setText("Card Id: " + userdata::getCardId());
    idCard=userdata::getCardId();
    startSetUp();

    timer = new QTimer( this );
    connect( timer, SIGNAL(timeout()), this, SLOT(TimerEnd()));
    timer->start( 30000 ); // 2 seconds single-shot timer

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
ui->bankView->clear();
    QByteArray response_data=reply->readAll();
      QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
      QJsonArray json_array = json_doc.array();
      for(int i =0 ; i <10;i++){
          QJsonObject json_obj = json_array[i].toObject();
           QString grade =  "";
          if(json_obj["sum"].toInt()>0){
               grade=json_obj["dateeu"].toString()+" | action: " + json_obj["action"].toString()+ " | sum: +" +QString::number(json_obj["sum"].toInt())+" | card id: "+
                                QString::number(json_obj["card_id"].toInt())+"\r\n";
          }else{
               grade=json_obj["dateeu"].toString()+" | action: " + json_obj["action"].toString()+ " | sum: " +QString::number(json_obj["sum"].toInt())+" | card id: "+
                                QString::number(json_obj["card_id"].toInt())+"\r\n";
      }
      /*foreach (const QJsonValue &value, json_array) {
          QJsonObject json_obj = value.toObject();
           QString grade =  "";
          if(json_obj["sum"].toInt()>0){
               grade=json_obj["dateeu"].toString()+" | action: " + json_obj["action"].toString()+ " | sum: +" +QString::number(json_obj["sum"].toInt())+" | card id: "+
                                QString::number(json_obj["card_id"].toInt())+"\r\n";
          }else{
               grade=json_obj["dateeu"].toString()+" | action: " + json_obj["action"].toString()+ " | sum: " +QString::number(json_obj["sum"].toInt())+" | card id: "+
                                QString::number(json_obj["card_id"].toInt())+"\r\n";
          }
*/

          ui->bankView->addItem(grade);

         // qDebug()<<"setEventsInView" + grade;

      }

        reply->deleteLater();
        //gradeManager->deleteLater();
}

void userHomePage::welcomeSlot(QNetworkReply *reply)
{
    response_balance=replyWelcome->readAll();
    qDebug()<<"DATA : "+response_balance;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_balance);
    QJsonArray json_array = json_doc.array();
    QString welcome = "";
    QString balance = "";
    QString credit = "";
    foreach (const QJsonValue &value, json_array) {
       QJsonObject json_obj = value.toObject();
      ui->welcomeTxt->setText( welcome+="Welcome, " +json_obj["fname"].toString() + " " + json_obj["lname"].toString());
       if( json_obj["balance"].toInt()>0){
           ui->balanceTxt->setText( balance ="balance: " + QString::number(json_obj["balance"].toInt()));
       }
       else{
          ui->balanceTxt->setText( balance ="balance: " + QString::number(json_obj["balance"].toInt()));
       }

       if( userdata::cardType == "credit"){
           ui->creditTxt->setText("Credit limit: " + QString::number(json_obj["credit_limit"].toInt()));
       }
       else{
           ui->creditTxt->setText("");

       }

       qDebug()<<"Welcome, " +json_obj["fname"].toString() + " " + json_obj["lname"].toString();

       userdata::credit_limit=json_obj["credit_limit"].toInt();
       userdata::balance=json_obj["balance"].toInt();

       qDebug()<<"cardId, " + userdata::getAccountId();


    }



    replyWelcome->deleteLater();
    gradeManager->deleteLater();
}

void userHomePage::startSetUp()
{
    qDebug()<<"startSetUp, webToken: " + userdata::getWebToken();


    QString site_url=MyUrl::getBaseUrl()+"/event/" +userdata::getAccountId() ;
    qDebug()<<site_url;
    //QString site_url=MyUrl::getBaseUrl()+"/event/1" ;

        QNetworkRequest request((site_url));
        //WEBTOKEN ALKU
        request.setRawHeader(QByteArray("Authorization"),(userdata::getWebToken()));
        //WEBTOKEN LOPPU
        gradeManager = new QNetworkAccessManager(this);

        connect(gradeManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(setEventsInView(QNetworkReply*)));

        reply = gradeManager->get(request);


    QString site_url2=MyUrl::getBaseUrl()+"/card/"+userdata::getCardId();
    QNetworkRequest request2((site_url2));
    //WEBTOKEN ALKU
    //QByteArray myToken="Bearer "+wb;
    request2.setRawHeader(QByteArray("Authorization"),(userdata::getWebToken()));
    //WEBTOKEN LOPPU
    gradeManager = new QNetworkAccessManager(this);

    connect(gradeManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(welcomeSlot(QNetworkReply*)));

    replyWelcome = gradeManager->get(request2);





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
    //ui->cardInfo->setText(book);


    reply->deleteLater();
    gradeManager->deleteLater();
}


void userHomePage::on_pushButton_2_clicked()
{
    objectDeposid = new DeposidCahs();
    objectDeposid->show();
    this->close();
}


void userHomePage::on_pushButton_clicked()
{
    objectEvent = new EventWindow();
    objectEvent->show();
    this->close();

}


void userHomePage::on_pushButton_3_clicked()
{
    startSetUp();

}


void userHomePage::on_sinoutB_clicked()
{
    userdata::cardId="";
    userdata::cardType="";
    userdata::accountId="";
    userdata::balance=0;
    userdata::credit_limit=0;
    userdata::webToken="";



    welcomeWindow *w = new welcomeWindow;
    w->show();
    this->close();
}

void userHomePage::TimerEnd()
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



void userHomePage::on_showAllB_clicked()
{
    allEventsWindow *w = new allEventsWindow();
    w->show();
    this->close();
}

