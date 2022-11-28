#ifndef USERHOMEPAGE_H
#define USERHOMEPAGE_H

#include <QDialog>

namespace Ui {
class userHomePage;
}

class userHomePage : public QDialog
{
    Q_OBJECT

public:
    explicit userHomePage(QString id_owner, QWidget *parent = nullptr);
    ~userHomePage();

private slots:
    void on_lableIdOwner_windowIconChanged(const QIcon &icon);

private:
    Ui::userHomePage *ui;
};

#endif // USERHOMEPAGE_H
