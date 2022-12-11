#include "eventwindow.h"
#include "ui_eventwindow.h"
#include "welcomeWindow.h"

EventWindow::EventWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EventWindow)
{
    ui->setupUi(this);
    setupCheck();
    timer = new QTimer( this );
    connect( timer, SIGNAL(timeout()), this, SLOT(TimerEnd()));
    timer->start( 30000 ); // 2 seconds single-shot timer


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

    if(ui->inputWith->text()!=""){
        eventUpdate(ui->inputWith->text());

    }

}

void EventWindow::checkInputB(QNetworkReply *reply)
{
    response_data=replyBalance->readAll();
    qDebug()<<"DATA : "+response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();

    if("true" == response_data){
        ui->inputPressed->setEnabled(true);
        ui->errorTxt->setText("");

    }else{
        ui->inputPressed->setEnabled(false);
        ui->errorTxt->setText("insufficient funds");

    }

    replyBalance->deleteLater();
    postBalanceManager->deleteLater();
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


void EventWindow::on_withd20_clicked()
{

createEvent("-20");
}


void EventWindow::on_withd40_clicked()
{
    createEvent("-40");

}


void EventWindow::on_withd50_clicked()
{
    createEvent("-50");

}


void EventWindow::on_withd100_clicked()
{
    createEvent("-100");

}


void EventWindow::on_inputPressed_clicked()
{
    createEvent("-"+ui->inputWith->text());

}

void EventWindow::createEvent(QString num)
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


    setupCheck();

}

void EventWindow::setupCheck()
{
    qDebug()<<"setupCheck";

    if(userdata::cardType=="credit"){
        if(userdata::credit_limit + userdata::balance >= 20){
            setButtonCon("20", true);
        }
        else{
            setButtonCon("20", false);

        }
       if(userdata::credit_limit + userdata::balance >= 40){
           setButtonCon("40", true);

        }
       else
       {
           setButtonCon("40", false);

       }



         if(userdata::credit_limit + userdata::balance >= 50){
             setButtonCon("50", true);

        }
        else
         {
             setButtonCon("50", false);

         }


        if(userdata::credit_limit + userdata::balance >= 100)
        {
            setButtonCon("100", true);
        }
        else{
            setButtonCon("100", false);

        }

    }else
    {
        if(userdata::balance >= 20){
            setButtonCon("20", true);
        }
        else{
            setButtonCon("20", false);

        }
       if(userdata::balance >= 40){
           setButtonCon("40", true);

        }
       else
       {
           setButtonCon("40", false);

       }


       if(userdata::balance >= 50){
             setButtonCon("50", true);
        }
        else
         {
             setButtonCon("50", false);
         }


        if( userdata::balance >= 100)
        {
            setButtonCon("100", true);
        }
        else
        {
            setButtonCon("100", false);
        }
    }

}

void EventWindow::setButtonCon(QString num, bool active)
{
    qDebug()<<num + " " +  QString::number(active);
    if(num == "20"){
        ui->withd20->setEnabled(active);
    }
    else if(num == "40"){
        ui->withd40->setEnabled(active);

    }
    else if(num == "50"){
        ui->withd50->setEnabled(active);

    }
    else if(num == "100"){
        ui->withd100->setEnabled(active);

    }

}





void EventWindow::on_inputWith_editingFinished()
{

}






void EventWindow::on_pushButton_5_clicked()
{
    userHomePage *uspag = new userHomePage();
    uspag->show();
    this->close();
}


void EventWindow::on_inputWith_textEdited(const QString &arg1)
{
eventUpdate(arg1);
}

void EventWindow::eventUpdate(QString input){
    QJsonObject jsonObj;
    jsonObj.insert("account_id",userdata::getAccountId());
    jsonObj.insert("card_type",userdata::getCardType());
    //jsonObj.insert("summa",ui->inputWith->text());
    jsonObj.insert("summa",input);

 qDebug()<<"account_id " + userdata::getAccountId() + " card_type " + userdata::getCardType();
    QString site_url=MyUrl::getBaseUrl()+"/balance_check";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    //WEBTOKEN ALKU
    request.setRawHeader(QByteArray("Authorization"),(userdata::getWebToken()));
    //WEBTOKEN LOPPU

    postBalanceManager = new QNetworkAccessManager(this);
    connect(postBalanceManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(checkInputB(QNetworkReply*)));


    replyBalance = postBalanceManager->post(request, QJsonDocument(jsonObj).toJson());
}

void EventWindow::TimerEnd()
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
        this->close();
    }

}

