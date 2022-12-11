#ifndef USERHOMEPAGE_H
#define USERHOMEPAGE_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <deposidcahs.h>
#include "myurl.h"
#include "userdata.h"
#include <eventwindow.h>

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
    QTimer *timer;

private slots:
    void on_lableIdOwner_windowIconChanged(const QIcon &icon);

    void on_accountB_clicked();

    void getCardSlot (QNetworkReply *reply);
    void setEventsInView(QNetworkReply *reply);
   void welcomeSlot(QNetworkReply *reply);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_sinoutB_clicked();
    void TimerEnd();

    void on_showAllB_clicked();

private:

    Ui::userHomePage *ui;
    QByteArray webToken;
    QString idCard;
    QString cardInfo;
    EventWindow *objectEvent;
    DeposidCahs *objectDeposid;

    QNetworkAccessManager *gradeManager;
    QNetworkReply *reply;
    QNetworkReply *replyWelcome;

    QByteArray response_data;
    QByteArray response_balance;

};

#endif // USERHOMEPAGE_H
