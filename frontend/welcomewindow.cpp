#include "welcomewindow.h"
#include "ui_welcomewindow.h"

welcomeWindow::welcomeWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::welcomeWindow)
{
    ui->setupUi(this);
}

welcomeWindow::~welcomeWindow()
{
    delete ui;
}

void welcomeWindow::on_pushButton_clicked()
{
    objWindow = new MainWindow();
    objWindow->show();
    this->close();

}

