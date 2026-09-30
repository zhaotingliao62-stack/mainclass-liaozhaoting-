QT += core gui widgets printsupport

CONFIG += c++17
TEMPLATE = app
TARGET = SignalViewer

SOURCES += \
    main.cpp \
    mainclass.cpp \
    qcustomplot.cpp

HEADERS += \
    mainclass.h \
    qcustomplot.h

FORMS += mainclass.ui

