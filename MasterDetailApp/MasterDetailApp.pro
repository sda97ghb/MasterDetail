QT += quick sql
CONFIG += c++11

DESTDIR = $$OUT_PWD/../bin

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += $$PWD/../MasterDetail/include

LIBS += -L$$OUT_PWD/../lib

LIBS += -lMasterDetail

SOURCES += main.cpp
