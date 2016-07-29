#-------------------------------------------------
#
# Project created by QtCreator 2016-06-03T20:16:45
#
#-------------------------------------------------

#运行时动态加载UI文件
QT += uitools

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myUi
TEMPLATE = app


SOURCES += main.cpp\
        myUi.cpp \
    subUi.cpp

HEADERS  += myUi.h\
#            G:\EXAMPLES_trunkwc\build-myUi-Desktop_Qt_5_5_1_MSVC2013_32bit-Debug\ui_myui.h \
    subUi.h

FORMS    += myui.ui \
    sub.ui

RESOURCES += \
    mysource.qrc
