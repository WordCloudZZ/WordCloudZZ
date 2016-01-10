#-------------------------------------------------
#
# Project created by QtCreator 2015-12-09T18:09:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NuageDeMotsGui
TEMPLATE = app

CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    BinarySearchTree.tpp \
    Countable.cpp \
    FileReader.tpp \
    HashElement.tpp \
    Hashtable.tpp \
    Mersenne.cpp \
    Node.tpp \
    WordsGenerator.cpp


HEADERS  += mainwindow.h \
    BinarySearchTree.h \
    Countable.h \
    FileReader.h \
    HashElement.h \
    Hashtable.h \
    Mersenne.h \
    Node.h \
    WordsGenerator.h


FORMS    += mainwindow.ui

DISTFILES +=
