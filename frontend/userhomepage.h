#ifndef USERHOMEPAGE_H
#define USERHOMEPAGE_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "myurl.h"
#include "userdata.h"

namespace Ui {
class userHomePage;
}

class userHomePage : public QDialog
{
    Q_OBJECT

public:
    explicit userHomePage( QWidget *parent = nullptr);
    ~userHomePage();

    void setWebToken(const QByteArray &newWebToken);
    const QByteArray &getWebToken() const;

    void startSetUp();
private slots:
    void on_lableIdOwner_windowIconChanged(const QIcon &icon);

    void on_accountB_clicked();

    void getCardSlot (QNetworkReply *reply);
    void setEventsInView(QNetworkReply *reply);


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
