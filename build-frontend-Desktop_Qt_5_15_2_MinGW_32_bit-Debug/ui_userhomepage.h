/********************************************************************************
** Form generated from reading UI file 'userhomepage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERHOMEPAGE_H
#define UI_USERHOMEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userHomePage
{
public:
    QLabel *accountTxt;
    QListWidget *bankView;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *welcomeTxt;
    QLabel *lableIdOwner;
    QLabel *balanceTxt;
    QLabel *creditTxt;
    QFrame *frame;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *sinoutB;
    QPushButton *showAllB;

    void setupUi(QDialog *userHomePage)
    {
        if (userHomePage->objectName().isEmpty())
            userHomePage->setObjectName(QString::fromUtf8("userHomePage"));
        userHomePage->resize(800, 600);
        userHomePage->setStyleSheet(QString::fromUtf8("background-color: rgb(49, 34, 68);\n"
""));
        accountTxt = new QLabel(userHomePage);
        accountTxt->setObjectName(QString::fromUtf8("accountTxt"));
        accountTxt->setGeometry(QRect(230, 200, 361, 31));
        accountTxt->setStyleSheet(QString::fromUtf8("color: white"));
        bankView = new QListWidget(userHomePage);
        bankView->setObjectName(QString::fromUtf8("bankView"));
        bankView->setGeometry(QRect(0, 230, 791, 331));
        bankView->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 100, 102);\n"
"color: rgb(212, 212, 212);"));
        bankView->setProperty("isWrapping", QVariant(false));
        horizontalLayoutWidget = new QWidget(userHomePage);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 30, 771, 171));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(horizontalLayoutWidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(20, 69, 82);\n"
"\n"
""));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayoutWidget = new QWidget(frame_2);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 371, 166));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        welcomeTxt = new QLabel(verticalLayoutWidget);
        welcomeTxt->setObjectName(QString::fromUtf8("welcomeTxt"));
        QFont font;
        font.setPointSize(20);
        welcomeTxt->setFont(font);
        welcomeTxt->setStyleSheet(QString::fromUtf8("color: rgb(224, 239, 255);"));

        verticalLayout->addWidget(welcomeTxt);

        lableIdOwner = new QLabel(verticalLayoutWidget);
        lableIdOwner->setObjectName(QString::fromUtf8("lableIdOwner"));
        lableIdOwner->setFont(font);
        lableIdOwner->setStyleSheet(QString::fromUtf8("color: rgb(224, 239, 255);"));

        verticalLayout->addWidget(lableIdOwner);

        balanceTxt = new QLabel(verticalLayoutWidget);
        balanceTxt->setObjectName(QString::fromUtf8("balanceTxt"));
        balanceTxt->setFont(font);
        balanceTxt->setStyleSheet(QString::fromUtf8("color: rgb(224, 239, 255);"));

        verticalLayout->addWidget(balanceTxt);

        creditTxt = new QLabel(verticalLayoutWidget);
        creditTxt->setObjectName(QString::fromUtf8("creditTxt"));
        creditTxt->setFont(font);
        creditTxt->setStyleSheet(QString::fromUtf8("color: rgb(224, 239, 255);"));

        verticalLayout->addWidget(creditTxt);


        horizontalLayout->addWidget(frame_2);

        frame = new QFrame(horizontalLayoutWidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(20, 69, 82);\n"
"\n"
""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(70, 30, 151, 41));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(6, 90, 96);\n"
"\n"
"color: white"));
        pushButton_2 = new QPushButton(frame);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(70, 100, 151, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(6, 90, 96);\n"
"\n"
"color: white"));
        pushButton_3 = new QPushButton(frame);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(300, 40, 80, 24));
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(6, 90, 96);\n"
"\n"
"color: white"));
        sinoutB = new QPushButton(frame);
        sinoutB->setObjectName(QString::fromUtf8("sinoutB"));
        sinoutB->setGeometry(QRect(300, 10, 80, 24));
        sinoutB->setStyleSheet(QString::fromUtf8("background-color: rgb(6, 90, 96);\n"
"\n"
"color: white"));

        horizontalLayout->addWidget(frame);

        showAllB = new QPushButton(userHomePage);
        showAllB->setObjectName(QString::fromUtf8("showAllB"));
        showAllB->setGeometry(QRect(710, 570, 80, 24));
        showAllB->setStyleSheet(QString::fromUtf8("background-color: rgb(6, 90, 96);\n"
"\n"
"color: white"));

        retranslateUi(userHomePage);

        QMetaObject::connectSlotsByName(userHomePage);
    } // setupUi

    void retranslateUi(QDialog *userHomePage)
    {
        userHomePage->setWindowTitle(QCoreApplication::translate("userHomePage", "Dialog", nullptr));
        accountTxt->setText(QCoreApplication::translate("userHomePage", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; color:#ffffff;\">Transactions</span></p></body></html>", nullptr));
        welcomeTxt->setText(QCoreApplication::translate("userHomePage", "<html><head/><body><p><span style=\" font-size:12pt; color:#ffffff;\">Welcome</span></p></body></html>", nullptr));
        lableIdOwner->setText(QCoreApplication::translate("userHomePage", "<html><head/><body><p><span style=\" font-size:12pt; color:#ffffff;\">num</span></p></body></html>", nullptr));
        balanceTxt->setText(QCoreApplication::translate("userHomePage", "<html><head/><body><p><span style=\" font-size:12pt; color:#ffffff;\">balance</span></p></body></html>", nullptr));
        creditTxt->setText(QCoreApplication::translate("userHomePage", "<html><head/><body><p><span style=\" font-size:12pt; color:#ffffff;\">credit</span></p></body></html>", nullptr));
        pushButton->setText(QCoreApplication::translate("userHomePage", "Withdraw Cash", nullptr));
        pushButton_2->setText(QCoreApplication::translate("userHomePage", "Deposit Cash", nullptr));
        pushButton_3->setText(QCoreApplication::translate("userHomePage", "Update", nullptr));
        sinoutB->setText(QCoreApplication::translate("userHomePage", "Sign Out", nullptr));
        showAllB->setText(QCoreApplication::translate("userHomePage", "ShowAll", nullptr));
    } // retranslateUi

};

namespace Ui {
    class userHomePage: public Ui_userHomePage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERHOMEPAGE_H
