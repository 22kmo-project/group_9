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

private slots:
    void addEvent (QNetworkReply *reply);


    void on_eventB_clicked();

private:
    Ui::EventWindow *ui;
    QNetworkAccessManager *postManager;
    QNetworkReply *reply;
    QByteArray response_data;

};

#endif // EVENTWINDOW_H
