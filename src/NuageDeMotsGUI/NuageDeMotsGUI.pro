#-------------------------------------------------
#
# Project created by QtCreator 2015-12-09T18:09:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NuageDeMotsGUI
TEMPLATE = app
INCLUDEPATH += ../NuageDeMots/include/
INCLUDEPATH += ../NuageDeMots/src/
CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    ../NuageDeMots/src/BinarySearchTree.tpp \
    ../NuageDeMots/src/Countable.cpp \
    ../NuageDeMots/src/FileReader.tpp \
    ../NuageDeMots/src/HashElement.tpp \
    ../NuageDeMots/src/Hashtable.tpp \
    ../NuageDeMots/src/PDFReader.cpp \
<<<<<<< HEAD
    TagCloud.cpp
=======
    processthread.cpp
>>>>>>> refs/remotes/origin/master


HEADERS  += mainwindow.h \
    ../NuageDeMots/include/BinarySearchTree.h \
    ../NuageDeMots/include/Countable.h \
    ../NuageDeMots/include/FileReader.h \
    ../NuageDeMots/include/HashElement.h \
    ../NuageDeMots/include/Hashtable.h \
    ../NuageDeMots/include/Node.h \
    ../NuageDeMots/include/pdf.h \
    ../NuageDeMots/include/PDFReader.h \
<<<<<<< HEAD
    TagCloud.h
=======
    processthread.h
>>>>>>> refs/remotes/origin/master


FORMS    += mainwindow.ui

DISTFILES +=

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../libraries/zlib/ -lz
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../libraries/zlib/ -lz
else:unix: LIBS += -L$$PWD/../../libraries/zlib/ -lz

INCLUDEPATH += $$PWD/../../libraries/zlib
DEPENDPATH += $$PWD/../../libraries/zlib
