#ifndef CARDTYPEWINDOW_H
#define CARDTYPEWINDOW_H

#include <QDialog>
#include "userdata.h"
#include <userhomepage.h>

namespace Ui {
class CardTypeWIndow;
}

class CardTypeWIndow : public QDialog
{
    Q_OBJECT

public:
    explicit CardTypeWIndow(QWidget *parent = nullptr);
    ~CardTypeWIndow();
    QTimer *timer;


private slots:
    void on_debitB_clicked();

    void on_creditB_clicked();
    void TimerEnd();

private:
    Ui::CardTypeWIndow *ui;
    userHomePage *objectUserHomePage;

};

#endif // CARDTYPEWINDOW_H
