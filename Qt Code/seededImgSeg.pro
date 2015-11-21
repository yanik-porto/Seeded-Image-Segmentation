#-------------------------------------------------
#
# Project created by QtCreator 2015-10-12T15:10:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = seededImgSeg
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    imglabel.cpp \
    engine.cpp \
    utilities.cpp

HEADERS  += mainwindow.h \
    imglabel.h \
    engine.h \
    utilities.h

FORMS    += mainwindow.ui

INCLUDEPATH += C:\opencv\opencv\mingw\install\include
LIBS += -L"C:\opencv\opencv\mingw\install\x64\mingw\bin"
LIBS += -lopencv_core2411 -lopencv_highgui2411 -lopencv_imgproc2411

#INCLUDEPATH += C:\PCL_dependencies\Eigen\include
#LIBS += -L"C:\PCL_dependencies\Eigen\bin"

RESOURCES += \
    icons.qrc
