#ifndef USERMAINWINDOW_H
#define USERMAINWINDOW_H

#include <QDialog>

namespace Ui {
class userMainWindows;
}

class userMainWindows : public QDialog
{
    Q_OBJECT

public:
    explicit userMainWindows(QWidget *parent = nullptr);
    ~userMainWindows();

private:
    Ui::userMainWindows *ui;
};

#endif // USERMAINWINDOW_H
