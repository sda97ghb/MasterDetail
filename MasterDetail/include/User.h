#ifndef USER_H
#define USER_H

#include <QMetaType>
#include <QSharedPointer>
#include <QString>

class User {
public:
    User(int id = -1, QString firstName = "", QString lastName = "", int age = minAge());

    bool isValid() const;

    int id() const;
    void setId(int id);

    QString firstName() const;
    void setFirstName(const QString& firstName);

    QString lastName() const;
    void setLastName(const QString& lastName);

    int age() const;
    void setAge(int age);

    static int minAge();
    static int maxAge();

private:
    int m_id;
    QString m_firstName;
    QString m_lastName;
    int m_age;
};

bool operator ==(const User& u1, const User& u2);

Q_DECLARE_METATYPE(QSharedPointer<User>)

#endif // USER_H
