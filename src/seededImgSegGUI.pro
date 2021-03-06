#-------------------------------------------------
#
# Project created by QtCreator 2015-10-12T15:10:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = seededImgSeg
TEMPLATE = app


SOURCES +=  apps/main.cpp\
            common/mainwindow.cpp \
            common/imglabel.cpp \
            common/utilities.cpp \
            common/engine.cpp

HEADERS  += common/mainwindow.h \
            common/imglabel.h \
            common/utilities.h \
            common/engine.h

FORMS    += common/mainwindow.ui

#INCLUDEPATH += C:\opencv\opencv\mingw\install\include
#LIBS += -L"C:\opencv\opencv\mingw\install\x64\mingw\bin"
#LIBS += -lopencv_core2411 -lopencv_highgui2411 -lopencv_imgproc2411

INCLUDEPATH += /usr/local/include
LIBS += -L"/usr/local/lib"
LIBS += -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs

RESOURCES +=
