#ifndef USERSVIEWMODEL_H
#define USERSVIEWMODEL_H

#include "User.h"

#include <QObject>
#include <QSharedPointer>

class UsersViewModel : public QObject {
    Q_OBJECT

//    Q_PROPERTY(QList<UserViewModel> users READ users WRITE setUsers NOTIFY usersChanged)
//    Q_PROPERTY(UserViewModel currentUser READ currentUser WRITE setCurrentUser NOTIFY currentUserChanged)
    Q_PROPERTY(QSharedPointer<User> user READ user WRITE setUser NOTIFY userChanged)

public:
    UsersViewModel();

    QSharedPointer<User> user() const;

public slots:
    void setUser(QSharedPointer<User> user);

signals:
    void userChanged(QSharedPointer<User> user);

private:
    QSharedPointer<User> m_user;
};

#endif // USERSVIEWMODEL_H
