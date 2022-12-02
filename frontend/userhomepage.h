#ifndef USERHOMEPAGE_H
#define USERHOMEPAGE_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "myurl.h"


namespace Ui {
class userHomePage;
}

class userHomePage : public QDialog
{
    Q_OBJECT

public:
    explicit userHomePage(QString id_card, QWidget *parent = nullptr);
    ~userHomePage();

    void setWebToken(const QByteArray &newWebToken);
    const QString &getWebToken() const;


private slots:
    void on_lableIdOwner_windowIconChanged(const QIcon &icon);

    void on_accountB_clicked();

    void getCardSlot (QNetworkReply *reply);


private:
    Ui::userHomePage *ui;
    QByteArray webToken;
    QString idCard;
    QString cardInfo;


    QNetworkAccessManager *gradeManager;
    QNetworkReply *reply;
    QByteArray response_data;
};

#endif // USERHOMEPAGE_H
