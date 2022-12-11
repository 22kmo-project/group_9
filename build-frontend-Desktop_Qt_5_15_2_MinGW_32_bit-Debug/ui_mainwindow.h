/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *cardNumEnter;
    QLineEdit *pinEnter;
    QPushButton *loginB;
    QLabel *errorTxt;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(799, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(49, 34, 68);\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, -20, 801, 191));
        label->setStyleSheet(QString::fromUtf8("color: rgb(33, 47, 69);\n"
"background-color: rgb(11, 82, 91)"));
        label->setAlignment(Qt::AlignCenter);
        cardNumEnter = new QLineEdit(centralwidget);
        cardNumEnter->setObjectName(QString::fromUtf8("cardNumEnter"));
        cardNumEnter->setGeometry(QRect(290, 250, 221, 41));
        cardNumEnter->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	border: 2px solid #144552;\n"
"	border-radius: 10px;\n"
"	color: white\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"	border: 2px solid #006466;\n"
"}"));
        cardNumEnter->setAlignment(Qt::AlignCenter);
        pinEnter = new QLineEdit(centralwidget);
        pinEnter->setObjectName(QString::fromUtf8("pinEnter"));
        pinEnter->setGeometry(QRect(290, 350, 221, 41));
        pinEnter->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	border: 2px solid #144552;\n"
"	border-radius: 10px;\n"
"	color: white\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"	border: 2px solid #006466;\n"
"}"));
        pinEnter->setAlignment(Qt::AlignCenter);
        loginB = new QPushButton(centralwidget);
        loginB->setObjectName(QString::fromUtf8("loginB"));
        loginB->setGeometry(QRect(360, 420, 91, 31));
        loginB->setStyleSheet(QString::fromUtf8("background-color: rgb(20, 69, 82);\n"
"color: white"));
        errorTxt = new QLabel(centralwidget);
        errorTxt->setObjectName(QString::fromUtf8("errorTxt"));
        errorTxt->setGeometry(QRect(150, 470, 511, 20));
        errorTxt->setStyleSheet(QString::fromUtf8("color: rgb(6, 90, 96);"));
        errorTxt->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(360, 220, 81, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(360, 320, 81, 16));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_3->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        cardNumEnter->raise();
        label->raise();
        pinEnter->raise();
        loginB->raise();
        errorTxt->raise();
        label_2->raise();
        label_3->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 799, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:700; font-style:italic; color:#fdffff;\">BankSimul</span></p></body></html>", nullptr));
        loginB->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        errorTxt->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:10pt; color:#ffffff;\">Card ID</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" color:#ffffff;\">PIN Code</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
