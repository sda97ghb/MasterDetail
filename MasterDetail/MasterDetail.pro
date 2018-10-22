QT += quick sql
CONFIG += c++14
TEMPLATE = lib

DESTDIR = $$OUT_PWD/../lib

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

INCLUDEPATH += $$PWD/include

RESOURCES += res/qml.qrc

HEADERS += \
    include/User.h \
    include/Pet.h \
    include/Repository/UserRepository.h \
    include/UsersViewModel.h \
    include/UserViewModel.h \
    include/IdFactory.h \
    include/UserFactory.h \
    include/Repository/SqlUserRepository.h \
    include/Repository/Repositories.h \
    include/Repository/MockSqlUserRepository.h

SOURCES += \
    src/User.cpp \
    src/Pet.cpp \
    src/UsersViewModel.cpp \
    src/UserViewModel.cpp \
    src/IdFactory.cpp \
    src/UserFactory.cpp \
    src/Repository/SqlUserRepository.cpp \
    src/Repository/Repositories.cpp \
    src/Repository/MockSqlUserRepository.cpp
