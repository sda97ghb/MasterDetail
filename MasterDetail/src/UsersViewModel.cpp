#include <QtDebug>

#include "Repository/UserRepository.h"
#include "UsersViewModel.h"

UsersViewModel::UsersViewModel() {
//    m_user = UserRepository::byId(0);
    qDebug() << m_user->id() << m_user->firstName() << m_user->lastName() << m_user->age();
}

QSharedPointer<User> UsersViewModel::user() const {
    return m_user;
}

void UsersViewModel::setUser(QSharedPointer<User> user) {
    if (m_user == user)
        return;

    m_user = user;
    emit userChanged(m_user);
}
