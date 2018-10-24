#include "Repository/Repositories.h"
#include "Repository/UserRepository.h"
#include "UserViewModel.h"

UserViewModel::UserViewModel(QSharedPointer<User> user, QObject *parent) :
	QObject(parent),
	m_user(user) {
}

UserViewModel::UserViewModel(const UserViewModel& other) {
	user() = other.user();
}

UserViewModel& UserViewModel::operator =(const UserViewModel& other) {
	setUser(other.user());
	return *this;
}

QString UserViewModel::firstName() const {
	return user().isNull() ? QString() : user()->firstName();
}

QString UserViewModel::lastName() const {
	return user().isNull() ? QString() : user()->lastName();
}

int UserViewModel::age() const {
	return user().isNull() ? User::minAge() : user()->age();
}

void UserViewModel::setFirstName(QString firstName) {
	if (user().isNull())
		return;

	if (updateWrapped(&User::firstName, &User::setFirstName, firstName))
		emit firstNameChanged(firstName);
}

void UserViewModel::setLastName(QString lastName) {
	if (user().isNull())
		return;

	if (updateWrapped(&User::lastName, &User::setLastName, lastName))
		emit lastNameChanged(lastName);
}

void UserViewModel::setAge(int age) {
	if (user().isNull())
		return;

	if (updateWrapped(&User::age, &User::setAge, age))
		emit ageChanged(age);
}

void UserViewModel::saveUser() {
	if (user().isNull())
		return;

	QSharedPointer<UserRepository> userRepository = Repositories::userRepository();
	userRepository->update(user());
}

User* UserViewModel::wrapped() const {
	return user().data();
}

void UserViewModel::setUser(QSharedPointer<User> user) {
	m_user = user;
	emit firstNameChanged(firstName());
	emit lastNameChanged(lastName());
	emit ageChanged(age());
}

QSharedPointer<User> UserViewModel::user() const {
	return m_user;
}

bool operator ==(const UserViewModel& o1, const UserViewModel& o2) {
	auto u1 = o1.user();
	auto u2 = o2.user();
	return (u1.isNull() && u2.isNull()) ||
		   (!u1.isNull() && !u2.isNull() && ((*u1) == (*u2)));
}
