#include "cardtypewindow.h"
#include "ui_cardtypewindow.h"

CardTypeWIndow::CardTypeWIndow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CardTypeWIndow)
{
    ui->setupUi(this);
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

