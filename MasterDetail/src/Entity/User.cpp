#include "Entity/User.h"

User::User(int id, QString firstName, QString lastName, int age) :
    m_id(id),
    m_firstName(firstName),
    m_lastName(lastName),
    m_age(age) {
}

bool User::isValid() const {
	return (m_id >= 0) &&
		   (!m_firstName.isEmpty() || !m_lastName.isEmpty()) &&
		   (m_age >= minAge() && m_age <= maxAge());
}

int User::id() const {
    return m_id;
}

void User::setId(int id) {
    m_id = id;
}

QString User::firstName() const {
    return m_firstName;
}

void User::setFirstName(const QString& firstName) {
    m_firstName = firstName;
}

QString User::lastName() const {
    return m_lastName;
}

void User::setLastName(const QString& lastName) {
    m_lastName = lastName;
}

int User::age() const {
    return m_age;
}

void User::setAge(int age) {
    if (age < minAge())
        age = minAge();
    if (age > maxAge())
        age = maxAge();
    m_age = age;
}

int User::minAge() {
    return 18;
}

int User::maxAge() {
    return 40;
}

bool operator ==(const User& u1, const User& u2) {
    return (u1.id() == u2.id()) &&
           (u1.firstName() == u2.firstName()) &&
           (u1.lastName() == u2.lastName()) &&
           (u1.age() == u2.age());
}
