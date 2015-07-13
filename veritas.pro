#-------------------------------------------------
#
# Project created by QtCreator 2015-07-03T19:38:46
#
#-------------------------------------------------

QT       += core

QT       += widgets

QT       += gui

TARGET = veritas
CONFIG   += console
CONFIG   += qt
QMAKE_CXXFLAGS += -std=c++11
CONFIG   -= app_bundle

TEMPLATE = app

LIBS += -L/usr/lib64
LIBS += -L/usr/local -L/usr -lboost_filesystem -lboost_system

SOURCES += \
    veritas_gui.cpp \
    compare_files.cpp \
    main.cpp \
    utils.cpp

FORMS += \
    veritas_gui.ui

HEADERS += \
    veritas_gui.hpp \
    ui_veritas_gui.hpp \
    utils.hpp \
    compare_files.hpp
