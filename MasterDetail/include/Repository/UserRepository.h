#ifndef USERREPOSITORY_H
#define USERREPOSITORY_H

#include "User.h"

#include <QList>
#include <QSharedPointer>

class UserRepository {
public:
    virtual ~UserRepository() = default;

    virtual QList<QSharedPointer<User>> allUsers() = 0;
    virtual QSharedPointer<User> byId(int id) = 0;
    virtual void insert(QSharedPointer<User> user) = 0;
    virtual void update(QSharedPointer<User> user) = 0;
    virtual void remove(QSharedPointer<User> user) = 0;
};

#endif // USERREPOSITORY_H
