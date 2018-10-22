#ifndef SQLUSERREPOSITORY_H
#define SQLUSERREPOSITORY_H

#include "UserRepository.h"

#include <QtSql>

class SqlUserRepository : public UserRepository {
public:
    class DBException : public std::logic_error {
    public:
        DBException(const char* message);
    };

    SqlUserRepository();

    virtual QList<QSharedPointer<User>> allUsers() override;
    virtual QSharedPointer<User> byId(int id) override;
    virtual void insert(QSharedPointer<User> user) override;
    virtual void update(QSharedPointer<User> user) override;
    virtual void remove(QSharedPointer<User> user) override;

protected:
    QSharedPointer<User> userFromQuery(QSqlQuery& query);

    void connectToDatabase();

    void checkConfiguration();
    bool thereIsUsersTable();
    void createUsersTable();

private:
    QSqlDatabase m_db;
};

#endif // SQLUSERREPOSITORY_H
