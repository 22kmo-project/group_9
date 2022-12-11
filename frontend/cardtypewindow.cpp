#include "cardtypewindow.h"
#include "ui_cardtypewindow.h"
#include "welcomeWindow.h"

CardTypeWIndow::CardTypeWIndow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CardTypeWIndow)
{
    ui->setupUi(this);


    timer = new QTimer( this );
    connect( timer, SIGNAL(timeout()), this, SLOT(TimerEnd()));
    timer->start( 30000 ); // 2 seconds single-shot timer
}

CardTypeWIndow::~CardTypeWIndow()
{
    delete ui;
}

void CardTypeWIndow::on_debitB_clicked()
{
    userdata::cardType = "debit";
    qDebug()<<"getCardType: " + userdata::getCardType();

    objectUserHomePage=new userHomePage();
    objectUserHomePage->show();
    this->close();


}


void CardTypeWIndow::on_creditB_clicked()
{
    userdata::cardType = "credit";
    qDebug()<<"getCardType: " + userdata::getCardType();


    objectUserHomePage=new userHomePage();
    objectUserHomePage->show();
    this->close();

}

void CardTypeWIndow::TimerEnd()
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

