#-------------------------------------------------
#
# Project created by QtCreator 2022-07-31T18:33:36
#
#-------------------------------------------------

QT       += core gui sql network  opengl  #winextras
QT       += serialport
QT       += xlsx
QT       += charts
#QT       += webkitwidgets
QT       += multimedia #axcontainer
QT       += widgets printsupport
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QQ_EXE
TEMPLATE = app
MOC_DIR             = temp/moc
RCC_DIR             = temp/rcc
UI_DIR              = temp/ui
OBJECTS_DIR         = temp/obj
DESTDIR             = bin
PRECOMPILED_HEADER  = head.h
RC_FILE             = other/main.rc
RESOURCES           += $$PWD/core_qss/qss.qrc
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
        main.cpp


INCLUDEPATH         += $$PWD
INCLUDEPATH         += $$PWD/api
INCLUDEPATH         += $$PWD/login
INCLUDEPATH         += $$PWD/form
#INCLUDEPATH         += $$PWD/core_common

include             ($$PWD/api/api.pri)
include             ($$PWD/form/formmain.pri)
include             ($$PWD/login/login.pri)
#include             ($$PWD/core_common/core_common.pri)

#RESOURCES += \
#    qrc.qrc

RESOURCES += \
    other/main.qrc \
    core_qss/qss.qrc

