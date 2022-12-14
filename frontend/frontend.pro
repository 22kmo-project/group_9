QT       += core gui
QT +=network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    alleventswindow.cpp \
    cardtypewindow.cpp \
    deposidcahs.cpp \
    eventwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    myurl.cpp \
    userdata.cpp \
    userhomepage.cpp \
    welcomewindow.cpp

HEADERS += \
    alleventswindow.h \
    cardtypewindow.h \
    deposidcahs.h \
    eventwindow.h \
    mainwindow.h \
    myurl.h \
    userdata.h \
    userhomepage.h \
    welcomewindow.h

FORMS += \
    alleventswindow.ui \
    cardtypewindow.ui \
    deposidcahs.ui \
    eventwindow.ui \
    mainwindow.ui \
    userhomepage.ui \
    welcomewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
