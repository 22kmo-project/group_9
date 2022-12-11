#include "alleventswindow.h"
#include "ui_alleventswindow.h"
#include "welcomeWindow.h"

allEventsWindow::allEventsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::allEventsWindow)
{
    ui->setupUi(this);

    timer = new QTimer( this );
    connect( timer, SIGNAL(timeout()), this, SLOT(TimerEnd()));
    timer->start( 30000 ); // 2 seconds single-shot timer
    Setup();
}

allEventsWindow::~allEventsWindow()
{
    delete ui;
}

void allEventsWindow::Setup()
{
      qDebug()<<"Setup ALLEvents";
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

void allEventsWindow::on_pushButton_clicked()
{
    userHomePage *w = new userHomePage;
    w->show();
    this->close();
}

void allEventsWindow::setEventsInView(QNetworkReply *reply)
{
    qDebug()<<"setEventsInView" ;
ui->bankView->clear();
    QByteArray response_data=reply->readAll();
      QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
      QJsonArray json_array = json_doc.array();
      foreach (const QJsonValue &value, json_array) {
          QJsonObject json_obj = value.toObject();
           QString grade =  "";
          if(json_obj["sum"].toInt()>0){
               grade=json_obj["dateeu"].toString()+" | action: " + json_obj["action"].toString()+ " | sum: +" +QString::number(json_obj["sum"].toInt())+" | card id: "+
                                QString::number(json_obj["card_id"].toInt())+"\r\n";
          }else{
               grade=json_obj["dateeu"].toString()+" | action: " + json_obj["action"].toString()+ " | sum: " +QString::number(json_obj["sum"].toInt())+" | card id: "+
                                QString::number(json_obj["card_id"].toInt())+"\r\n";
          }


          ui->bankView->addItem(grade);

         // qDebug()<<"setEventsInView" + grade;

      }

        reply->deleteLater();
        //gradeManager->deleteLater();
}

void allEventsWindow::TimerEnd()
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
