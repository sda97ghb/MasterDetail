#include <QSharedPointer>
#include <QVariant>
#include <QtDebug>

#include "Repository/Repositories.h"
#include "Repository/UserRepository.h"
#include "UsersViewModel.h"

UsersViewModel::UsersViewModel(QObject* parent) :
    QObject(parent),
    m_currentUser(nullptr) {
}

QVariantList UsersViewModel::users() const {
    QSharedPointer<UserRepository> repo = Repositories::userRepository();
    QVariantList userVMs;
    for (QSharedPointer<User> user : repo->allUsers())
        userVMs.append(QVariant::fromValue(new UserViewModel(user, parent())));
    return userVMs;
}

QVariant UsersViewModel::currentUser() const {
    return QVariant::fromValue(m_currentUser);
}

void UsersViewModel::setCurrentUser(QVariant currentUser) {
    if (m_currentUser == currentUser.value<UserViewModel*>())
        return;

    m_currentUser = currentUser.value<UserViewModel*>();
    emit currentUserChanged(QVariant::fromValue(m_currentUser));
}
