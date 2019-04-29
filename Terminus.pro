#-------------------------------------------------
#
# Project created by QtCreator 2019-02-21T16:00:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Terminus
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
    commands/cd.cpp \
        mainwindow.cpp \
    console.cpp \
    inputparser.cpp \
    commands/command.cpp \
    commands/ls.cpp \
    file.cpp \
    folder.cpp \
    user.cpp \
    color.cpp \
    commands/cat.cpp \
    commands/echo.cpp \
    commands/chmod.cpp \
    commands/man.cpp

HEADERS  += mainwindow.h \
    commands/cd.h \
    console.h \
    inputparser.h \
    commands/ls.h \
    commands/command.h \
    file.h \
    folder.h \
    user.h \
    color.h \
    commands/cat.h \
    commands/echo.h \
    commands/chmod.h \
    commands/man.h

FORMS    += mainwindow.ui
