#ifndef USERVIEWMODEL_H
#define USERVIEWMODEL_H

#include "User.h"
#include "WrapperViewModel.h"

#include <QObject>
#include <QSharedPointer>

class UserViewModel : public QObject, public WrapperViewModel<User> {
    Q_OBJECT

	Q_PROPERTY(QString firstName READ firstName WRITE setFirstName NOTIFY firstNameChanged)
	Q_PROPERTY(QString lastName READ lastName WRITE setLastName NOTIFY lastNameChanged)
	Q_PROPERTY(int age READ age WRITE setAge NOTIFY ageChanged)

public:
	explicit UserViewModel(QSharedPointer<User> user = nullptr, QObject *parent = nullptr);
	UserViewModel(const UserViewModel& other);

	UserViewModel& operator =(const UserViewModel& other);

	QString firstName() const;
	QString lastName() const;
	int age() const;

	QSharedPointer<User> user() const;

signals:
	void firstNameChanged(QString firstName);
	void lastNameChanged(QString lastName);
	void ageChanged(int age);

public slots:
	void setFirstName(QString firstName);
	void setLastName(QString lastName);
	void setAge(int age);

	void saveUser();

protected:
	virtual User* wrapped() const override;

private:
	void setUser(QSharedPointer<User> user);

	QSharedPointer<User> m_user;
};

bool operator ==(const UserViewModel& o1, const UserViewModel& o2);

#endif // USERVIEWMODEL_H
