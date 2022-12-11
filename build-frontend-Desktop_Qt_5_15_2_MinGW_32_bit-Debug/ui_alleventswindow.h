/********************************************************************************
** Form generated from reading UI file 'alleventswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ALLEVENTSWINDOW_H
#define UI_ALLEVENTSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_allEventsWindow
{
public:
    QListWidget *bankView;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *allEventsWindow)
    {
        if (allEventsWindow->objectName().isEmpty())
            allEventsWindow->setObjectName(QString::fromUtf8("allEventsWindow"));
        allEventsWindow->resize(1274, 550);
        allEventsWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(39, 38, 64);"));
        bankView = new QListWidget(allEventsWindow);
        bankView->setObjectName(QString::fromUtf8("bankView"));
        bankView->setGeometry(QRect(240, 90, 851, 411));
        bankView->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 100, 102);\n"
"color: rgb(212, 212, 212);"));
        bankView->setProperty("isWrapping", QVariant(false));
        label = new QLabel(allEventsWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(240, 30, 841, 41));
        pushButton = new QPushButton(allEventsWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(1150, 490, 101, 41));
        pushButton->setStyleSheet(QString::fromUtf8("color:white;\n"
"background-color: rgb(11, 82, 91);"));

        retranslateUi(allEventsWindow);

        QMetaObject::connectSlotsByName(allEventsWindow);
    } // setupUi

    void retranslateUi(QDialog *allEventsWindow)
    {
        allEventsWindow->setWindowTitle(QCoreApplication::translate("allEventsWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("allEventsWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; color:#d9d9d9;\">Events</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("allEventsWindow", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class allEventsWindow: public Ui_allEventsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ALLEVENTSWINDOW_H
