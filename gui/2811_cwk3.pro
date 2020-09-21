######################################################################
# Automatically generated by qmake (3.1) Sat Jul 14 20:55:22 2018
######################################################################

TEMPLATE = app
TARGET = 2811_gui
INCLUDEPATH += .
QT += widgets
QMAKE_CXXFLAGS += -Wall -std=c++11
LIBS = -lgit2

# The following define makes your compiler warn you if you use any
# feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Input
HEADERS += window.h tabs.h
SOURCES += globals.cc main.cc window.cc tabs.cc

# just link demo tabs
# LIBS += sc17hkh.o ll16kdt.o bs15av.o ll14a5w.o

# rebuild demo tabs
SOURCES += sc17hkh.cc bs15av.cc ll16kdt.cc ll14a5w.cc

