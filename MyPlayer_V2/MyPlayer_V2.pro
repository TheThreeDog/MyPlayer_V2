#-------------------------------------------------
#
# Project created by QtCreator 2017-02-27T16:55:06
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyPlayer_V2
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    ThreeDog/tdabstractbutton.cpp \
    ThreeDog/tdcheckbox.cpp \
    ThreeDog/tdfadeoutwidget.cpp \
    ThreeDog/tdlistwidget.cpp \
    ThreeDog/tdmenubutton.cpp \
    ThreeDog/tdpushbutton.cpp \
    ThreeDog/tdradiobutton.cpp \
    ThreeDog/tdradiobuttongroup.cpp \
    ThreeDog/tdscrollarea.cpp \
    ThreeDog/tdslider.cpp \
    ThreeDog/tdstackbutton.cpp \
    ThreeDog/tdtoolbar.cpp \
    ThreeDog/tdwidget.cpp \
    myplaylist.cpp \
    myplaylistitem.cpp

HEADERS  += widget.h \
    ThreeDog/tdabstractbutton.h \
    ThreeDog/tdcheckbox.h \
    ThreeDog/tdfadeoutwidget.h \
    ThreeDog/tdlistwidget.h \
    ThreeDog/tdmenubutton.h \
    ThreeDog/tdpushbutton.h \
    ThreeDog/tdradiobutton.h \
    ThreeDog/tdradiobuttongroup.h \
    ThreeDog/tdscrollarea.h \
    ThreeDog/tdslider.h \
    ThreeDog/tdstackbutton.h \
    ThreeDog/tdtoolbar.h \
    ThreeDog/tdwidget.h \
    myplaylist.h \
    myplaylistitem.h

RESOURCES += \
    img.qrc
