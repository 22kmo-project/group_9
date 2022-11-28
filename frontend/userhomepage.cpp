#include "userhomepage.h"
#include "ui_userhomepage.h"

userHomePage::userHomePage(QString id_owner, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userHomePage)
{
    ui->setupUi(this);
    ui->lableIdOwner->setText(id_owner);
}

userHomePage::~userHomePage()
{
    delete ui;
}

void userHomePage::on_lableIdOwner_windowIconChanged(const QIcon &icon)
{

}

