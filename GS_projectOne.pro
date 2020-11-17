#-------------------------------------------------
#
# Project created by QtCreator 2020-10-06T08:21:56
#
#-------------------------------------------------

QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GS_projectOne
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        gs_windowone.cpp \
    gs_registerdialog.cpp \
    gs_frequencydialog.cpp \
    gs_mysqldialog.cpp \
    gs_tcpparadialog.cpp \
    gs_acquisitionobject.cpp \
    gs_mysqlobject.cpp \
    gs_acquisitiondialog.cpp \
    gs_functionframe.cpp \
    gs_tcpsimensobject.cpp \
    gs_changetwotooneobject.cpp \
    gs_processtcpobject.cpp \
    gs_processstatusobject.cpp \
    gs_changetoqpointfobject.cpp

HEADERS += \
        gs_windowone.h \
    gs_registerdialog.h \
    gs_frequencydialog.h \
    gs_mysqldialog.h \
    gs_tcpparadialog.h \
    gs_acquisitionobject.h \
    gs_mysqlobject.h \
    gs_acquisitiondialog.h \
    gs_acquisitionparameter.h \
    gs_functionframe.h \
    gs_tcpsimensobject.h \
    gs_changetwotooneobject.h \
    gs_processtcpobject.h \
    gs_processstatusobject.h \
    gs_deviceparameter.h \
    gs_changetoqpointfobject.h \
    gs_configure.h \
    gs_acquisitionallpara.h

FORMS += \
        gs_windowone.ui \
    gs_registerdialog.ui \
    gs_frequencydialog.ui \
    gs_mysqldialog.ui \
    gs_tcpparadialog.ui \
    gs_acquisitiondialog.ui
RC_ICONS = mytubiao.ico
