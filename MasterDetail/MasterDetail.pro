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
    include/Entity/Order.h \
    include/Entity/User.h \
    include/Factory/UserFactory.h \
    include/Repository/User/MockSqlUserRepository.h \
    include/Repository/User/SqlUserRepository.h \
    include/Repository/User/UserRepository.h \
    include/Repository/Repositories.h \
    include/Support/IdFactory.h \
    include/Support/MethodTypes.h \
    include/ViewModel/UsersViewModel.h \
    include/ViewModel/UserViewModel.h \
    include/ViewModel/WrapperViewModel.h \
    include/Entity/Product.h

SOURCES += \
    src/Entity/Order.cpp \
    src/Entity/User.cpp \
    src/Factory/UserFactory.cpp \
    src/Repository/User/MockSqlUserRepository.cpp \
    src/Repository/User/SqlUserRepository.cpp \
    src/Repository/Repositories.cpp \
    src/Support/IdFactory.cpp \
    src/ViewModel/UsersViewModel.cpp \
    src/ViewModel/UserViewModel.cpp \
    src/Entity/Product.cpp
