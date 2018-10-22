#include "IdFactory.h"
#include "UserFactory.h"

QSharedPointer<User> UserFactory::create(QString firstName, QString lastName, int age) {
    return QSharedPointer<User>::create(IdFactory::nextId(), firstName, lastName, age);
}

QSharedPointer<User> UserFactory::clone(QSharedPointer<User> other) {
    return other.isNull()
           ? nullptr
           : QSharedPointer<User>::create(*other);
}
