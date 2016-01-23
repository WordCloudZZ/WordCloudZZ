#-------------------------------------------------
#
# Project created by QtCreator 2016-01-10T17:40:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RandomSentencesGUI
TEMPLATE = app
INCLUDEPATH += ../RandomSentences/include/
CONFIG += c++11


SOURCES += main.cpp\
        mainwindow.cpp \
    ../RandomSentences/src/Stats.cpp \
    ../RandomSentences/src/Student.cpp \
    ../RandomSentences/src/WordsGenerator.cpp

HEADERS  += mainwindow.h \
    ../RandomSentences/include/Stats.h \
    ../RandomSentences/include/Student.h \
    ../RandomSentences/include/WordsGenerator.h

FORMS    += mainwindow.ui
