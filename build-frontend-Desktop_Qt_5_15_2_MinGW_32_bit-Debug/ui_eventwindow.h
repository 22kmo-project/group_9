/********************************************************************************
** Form generated from reading UI file 'eventwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTWINDOW_H
#define UI_EVENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EventWindow
{
public:
    QFrame *frame;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *withd20;
    QPushButton *withd50;
    QPushButton *withd40;
    QPushButton *withd100;
    QPushButton *pushButton_5;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *inputWith;
    QPushButton *inputPressed;
    QLabel *errorTxt;
    QLabel *label;

    void setupUi(QDialog *EventWindow)
    {
        if (EventWindow->objectName().isEmpty())
            EventWindow->setObjectName(QString::fromUtf8("EventWindow"));
        EventWindow->resize(1001, 594);
        EventWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(49, 34, 68);\n"
"\n"
""));
        frame = new QFrame(EventWindow);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(210, 100, 661, 471));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(20, 69, 82);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayoutWidget = new QWidget(frame);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(160, 200, 351, 181));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        withd20 = new QPushButton(gridLayoutWidget);
        withd20->setObjectName(QString::fromUtf8("withd20"));
        withd20->setEnabled(true);
        withd20->setStyleSheet(QString::fromUtf8("font: 18pt \"Segoe UI\";\n"
"background-color: rgb(6, 90, 96);\n"
"\n"
""));

        gridLayout->addWidget(withd20, 0, 0, 1, 1);

        withd50 = new QPushButton(gridLayoutWidget);
        withd50->setObjectName(QString::fromUtf8("withd50"));
        withd50->setStyleSheet(QString::fromUtf8("font: 18pt \"Segoe UI\";\n"
"background-color: rgb(6, 90, 96);\n"
"\n"
""));

        gridLayout->addWidget(withd50, 1, 0, 1, 1);

        withd40 = new QPushButton(gridLayoutWidget);
        withd40->setObjectName(QString::fromUtf8("withd40"));
        withd40->setStyleSheet(QString::fromUtf8("font: 18pt \"Segoe UI\";\n"
"background-color: rgb(6, 90, 96);\n"
"\n"
""));

        gridLayout->addWidget(withd40, 0, 1, 1, 1);

        withd100 = new QPushButton(gridLayoutWidget);
        withd100->setObjectName(QString::fromUtf8("withd100"));
        withd100->setStyleSheet(QString::fromUtf8("font: 18pt \"Segoe UI\";\n"
"background-color: rgb(6, 90, 96);\n"
"\n"
""));

        gridLayout->addWidget(withd100, 1, 1, 1, 1);

        pushButton_5 = new QPushButton(frame);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(520, 430, 131, 31));
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: rgb(6, 90, 96);\n"
"\n"
"color: white"));
        horizontalLayoutWidget = new QWidget(frame);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(160, 90, 351, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        inputWith = new QLineEdit(horizontalLayoutWidget);
        inputWith->setObjectName(QString::fromUtf8("inputWith"));

        horizontalLayout->addWidget(inputWith);

        inputPressed = new QPushButton(horizontalLayoutWidget);
        inputPressed->setObjectName(QString::fromUtf8("inputPressed"));
        inputPressed->setEnabled(false);
        inputPressed->setStyleSheet(QString::fromUtf8("background-color: rgb(6, 90, 96);\n"
"\n"
""));

        horizontalLayout->addWidget(inputPressed);

        errorTxt = new QLabel(frame);
        errorTxt->setObjectName(QString::fromUtf8("errorTxt"));
        errorTxt->setGeometry(QRect(160, 170, 351, 31));
        errorTxt->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 4);"));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 20, 341, 41));

        retranslateUi(EventWindow);

        QMetaObject::connectSlotsByName(EventWindow);
    } // setupUi

    void retranslateUi(QDialog *EventWindow)
    {
        EventWindow->setWindowTitle(QCoreApplication::translate("EventWindow", "Dialog", nullptr));
        withd20->setText(QCoreApplication::translate("EventWindow", "20", nullptr));
        withd50->setText(QCoreApplication::translate("EventWindow", "50", nullptr));
        withd40->setText(QCoreApplication::translate("EventWindow", "40", nullptr));
        withd100->setText(QCoreApplication::translate("EventWindow", "100", nullptr));
        pushButton_5->setText(QCoreApplication::translate("EventWindow", "Close", nullptr));
        inputWith->setInputMask(QString());
        inputPressed->setText(QCoreApplication::translate("EventWindow", "Withdraw", nullptr));
        errorTxt->setText(QCoreApplication::translate("EventWindow", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
        label->setText(QCoreApplication::translate("EventWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; color:#ebebeb;\">Withdraw Cash</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EventWindow: public Ui_EventWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTWINDOW_H
