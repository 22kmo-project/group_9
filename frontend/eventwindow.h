#ifndef EVENTWINDOW_H
#define EVENTWINDOW_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "userdata.h"
#include "myurl.h"

namespace Ui {
class EventWindow;
}

class EventWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EventWindow(QWidget *parent = nullptr);
    ~EventWindow();
    QTimer *timer;

    void setupCheck();
    void setButtonCon(QString num, bool active);
private slots:
    void addEvent (QNetworkReply *reply);
    void checkInputB (QNetworkReply *reply);


    void on_eventB_clicked();

    void on_withd20_clicked();

    void on_withd40_clicked();

    void on_withd50_clicked();

    void on_withd100_clicked();

    void on_inputPressed_clicked();

    void createEvent(QString num);


    void on_inputWith_editingFinished();


    void on_pushButton_5_clicked();

    void on_inputWith_textEdited(const QString &arg1);

    void eventUpdate(QString input);

    void TimerEnd();

private:
    Ui::EventWindow *ui;
    QNetworkAccessManager *postManager;
    QNetworkReply *reply;
    QByteArray response_data;

    QNetworkAccessManager *postBalanceManager;

    QNetworkReply *replyBalance;
    QByteArray response_data_balance;
    QString buttonNum;
};

#endif // EVENTWINDOW_H
