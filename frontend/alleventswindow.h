#ifndef ALLEVENTSWINDOW_H
#define ALLEVENTSWINDOW_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <deposidcahs.h>
#include "myurl.h"
#include "userdata.h"
#include <eventwindow.h>

namespace Ui {
class allEventsWindow;
}

class allEventsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit allEventsWindow(QWidget *parent = nullptr);
    ~allEventsWindow();

    void Setup();

    QTimer *timer;

private slots:
    void on_pushButton_clicked();
    void setEventsInView(QNetworkReply *reply);
    void TimerEnd();


private:
    Ui::allEventsWindow *ui;
    QByteArray webToken;
    QString idCard;
    QString cardInfo;

    QNetworkAccessManager *gradeManager;
    QNetworkReply *reply;
    QNetworkReply *replyWelcome;

    QByteArray response_data;
    QByteArray response_balance;
};

#endif // ALLEVENTSWINDOW_H
