#include "usermainwindow.h"
#include "ui_usermainwindow.h"

userMainWindow::userMainWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userMainWindow)
{
    ui->setupUi(this);
}

userMainWindow::~userMainWindow()
{
    delete ui;
}
