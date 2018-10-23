#ifndef USERSVIEWMODEL_H
#define USERSVIEWMODEL_H

#include "User.h"
#include "UserViewModel.h"

#include <QObject>
#include <QSharedPointer>
#include <QVariantList>

class UsersViewModel : public QObject {
    Q_OBJECT

	Q_PROPERTY(QVariantList users READ users NOTIFY usersChanged)
	Q_PROPERTY(QVariant currentUser READ currentUser WRITE setCurrentUser NOTIFY currentUserChanged)

public:
	UsersViewModel(QObject* parent = nullptr);

	QVariantList users() const;
	QVariant currentUser() const;

public slots:
	void setCurrentUser(QVariant currentUser);

signals:
	void usersChanged(QVariantList users);
	void currentUserChanged(QVariant currentUser);

private:
	UserViewModel* m_currentUser;
	QVariantList m_users;
};

#endif // USERSVIEWMODEL_H
