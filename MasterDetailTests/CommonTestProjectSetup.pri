QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

DESTDIR = $$OUT_PWD/../../tests

INCLUDEPATH += $$PWD/../MasterDetail/include

LIBS += -L$$OUT_PWD/../../lib

LIBS += -lMasterDetail
