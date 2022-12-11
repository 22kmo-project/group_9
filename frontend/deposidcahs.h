#ifndef DEPOSIDCAHS_H
#define DEPOSIDCAHS_H


#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "userdata.h"
#include "myurl.h"


namespace Ui {
class DeposidCahs;
}

class DeposidCahs : public QDialog
{
    Q_OBJECT

public:
    explicit DeposidCahs(QWidget *parent = nullptr);
    ~DeposidCahs();
    void createEvent(QString num);
    //void SetUserPage(userHomePage onj);
private slots:
    void addEvent (QNetworkReply *reply);

    void on_withd20_clicked();

    void on_withd40_clicked();

    void on_withd50_clicked();

    void on_withd100_clicked();

    void on_pushButton_5_clicked();

    void on_inputWith_editingFinished();

    void on_inputPressed_clicked();

private:
    Ui::DeposidCahs *ui;
    QNetworkAccessManager *postManager;
    QNetworkReply *reply;
    QByteArray response_data;

    QNetworkReply *replyBalance;
    QByteArray response_data_balance;
    //userHomePage *objHomePage;
};

#endif // DEPOSIDCAHS_H
