#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QDialog>
#include <mainwindow.h>

namespace Ui {
class welcomeWindow;
}

class welcomeWindow : public QDialog
{
    Q_OBJECT

public:
    explicit welcomeWindow(QWidget *parent = nullptr);
    ~welcomeWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::welcomeWindow *ui;
    MainWindow *objWindow;
};

#endif // WELCOMEWINDOW_H
