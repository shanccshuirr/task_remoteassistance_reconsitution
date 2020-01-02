QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = task_remoteassistance
TEMPLATE = app
CONFIG += c++11 link_pkgconfig
PKGCONFIG += dtkwidget



include(Help/help.pri)

HEADERS += \
    assistancecontrol.h \
    assistancewindow.h \
    widgetbase.h \
    mainview.h \
    waitview.h \
    displayview.h \
    copyview.h \
    inputview.h \
    connectview.h \
    connectsuccessview.h \
    connectfailview.h \
    layout.h


SOURCES += \
    assistancecontrol.cpp \
    assistancewindow.cpp \
    main.cpp \
    widgetbase.cpp \
    mainview.cpp \
    waitview.cpp \
    displayview.cpp \
    copyview.cpp \
    inputview.cpp \
    connectview.cpp \
    connectsuccessview.cpp \
    connectfailview.cpp \
    layout.cpp




DISTFILES +=

RESOURCES += \
    resouce.qrc
