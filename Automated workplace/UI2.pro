QT       += core gui sql network
QT += core network
QT += core

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialog.cpp \
    main.cpp \
    mainwindow.cpp \
    register.cpp \
    secondwindow.cpp \
    server.cpp \
    windbshow.cpp

HEADERS += \
    dialog.h \
    mainwindow.h \
    register.h \
    secondwindow.h \
    server.h \
    windbshow.h

FORMS += \
    dialog.ui \
    mainwindow.ui \
    register.ui \
    secondwindow.ui \
    windbshow.ui

win32:RC_FILE = iconka.rc
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
