/********************************************************************************
** Form generated from reading UI file 'cardtypewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARDTYPEWINDOW_H
#define UI_CARDTYPEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_CardTypeWIndow
{
public:
    QPushButton *debitB;
    QPushButton *creditB;
    QLabel *label;

    void setupUi(QDialog *CardTypeWIndow)
    {
        if (CardTypeWIndow->objectName().isEmpty())
            CardTypeWIndow->setObjectName(QString::fromUtf8("CardTypeWIndow"));
        CardTypeWIndow->resize(480, 438);
        CardTypeWIndow->setStyleSheet(QString::fromUtf8("background-color: rgb(49, 34, 68);\n"
"\n"
""));
        debitB = new QPushButton(CardTypeWIndow);
        debitB->setObjectName(QString::fromUtf8("debitB"));
        debitB->setGeometry(QRect(70, 220, 131, 61));
        debitB->setStyleSheet(QString::fromUtf8("background-color: rgb(20, 69, 82);\n"
"\n"
""));
        creditB = new QPushButton(CardTypeWIndow);
        creditB->setObjectName(QString::fromUtf8("creditB"));
        creditB->setGeometry(QRect(250, 220, 131, 61));
        creditB->setStyleSheet(QString::fromUtf8("background-color: rgb(20, 69, 82);\n"
"\n"
""));
        label = new QLabel(CardTypeWIndow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 140, 191, 41));
        label->setStyleSheet(QString::fromUtf8("color: rgb(0, 100, 102);\n"
"\n"
""));

        retranslateUi(CardTypeWIndow);

        QMetaObject::connectSlotsByName(CardTypeWIndow);
    } // setupUi

    void retranslateUi(QDialog *CardTypeWIndow)
    {
        CardTypeWIndow->setWindowTitle(QCoreApplication::translate("CardTypeWIndow", "Dialog", nullptr));
        debitB->setText(QCoreApplication::translate("CardTypeWIndow", "Debit", nullptr));
        creditB->setText(QCoreApplication::translate("CardTypeWIndow", "Credit", nullptr));
        label->setText(QCoreApplication::translate("CardTypeWIndow", "<html><head/><body><p align=\"center\"><span style=\" font-size:22pt;\">CardType</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CardTypeWIndow: public Ui_CardTypeWIndow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARDTYPEWINDOW_H
