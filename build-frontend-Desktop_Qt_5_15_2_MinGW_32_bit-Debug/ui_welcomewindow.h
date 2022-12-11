/********************************************************************************
** Form generated from reading UI file 'welcomewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMEWINDOW_H
#define UI_WELCOMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_welcomeWindow
{
public:
    QFrame *frame;
    QPushButton *pushButton;
    QLabel *label_2;

    void setupUi(QDialog *welcomeWindow)
    {
        if (welcomeWindow->objectName().isEmpty())
            welcomeWindow->setObjectName(QString::fromUtf8("welcomeWindow"));
        welcomeWindow->resize(975, 581);
        welcomeWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(49, 34, 68);\n"
""));
        frame = new QFrame(welcomeWindow);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(190, 100, 591, 391));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(27, 58, 75);"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(210, 303, 181, 41));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(62, 31, 71);\n"
"\n"
"color: rgb(255, 255, 255);"));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 10, 551, 181));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(33, 47, 69);\n"
"background-color: rgb(11, 82, 91)"));
        label_2->setAlignment(Qt::AlignCenter);

        retranslateUi(welcomeWindow);

        QMetaObject::connectSlotsByName(welcomeWindow);
    } // setupUi

    void retranslateUi(QDialog *welcomeWindow)
    {
        welcomeWindow->setWindowTitle(QCoreApplication::translate("welcomeWindow", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("welcomeWindow", "InserdCard", nullptr));
        label_2->setText(QCoreApplication::translate("welcomeWindow", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:700; font-style:italic; color:#fdffff;\">Welcome to BankSimul!</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class welcomeWindow: public Ui_welcomeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMEWINDOW_H
