#ifndef USERFACTORY_H
#define USERFACTORY_H

#include "User.h"

#include <QSharedPointer>

class UserFactory {
public:
    static QSharedPointer<User> create(QString firstName, QString lastName, int age);
    static QSharedPointer<User> clone(QSharedPointer<User> other);
};

#endif // USERFACTORY_H
