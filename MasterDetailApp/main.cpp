#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QtDebug>

#include "UsersViewModel.h"
#include "UserViewModel.h"

int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<UsersViewModel>("MyTypes", 1, 0, "UsersViewModel");
	qmlRegisterUncreatableType<UserViewModel>("MyTypes", 1, 0, "UserViewModel", "Unable to create UserViewModel");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/qml/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
