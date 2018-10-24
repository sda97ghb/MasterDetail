#include "Repository/SqlUserRepository.h"

SqlUserRepository::SqlUserRepository() {
    connectToDatabase();
    checkConfiguration();
}

QList<QSharedPointer<User>> SqlUserRepository::allUsers() {
    QSqlQuery query("select * from users", m_db);

    if (!query.isActive())
        throw DBException("Unable to get the data from the database");

    QList<QSharedPointer<User>> users;
    while (query.next())
        users.append(userFromQuery(query));
    return users;
}

QSharedPointer<User> SqlUserRepository::byId(int id) {
    QSqlQuery query(m_db);
    query.prepare("select * from users where id = :id");
    query.bindValue(":id", id);
    query.exec();

    if (!query.isActive())
        throw DBException("Unable to get the data from the database");

    if (!query.next())
        return nullptr;
    QSharedPointer<User> user = userFromQuery(query);
    return user;
}

void SqlUserRepository::insert(QSharedPointer<User> user) {
    if (user.isNull())
        return;

    QSqlQuery query(m_db);
    query.prepare("insert into users values(:id, :firstname, :lastname, :age)");
    query.bindValue(":id", user->id());
    query.bindValue(":firstname", user->firstName());
    query.bindValue(":lastname", user->lastName());
    query.bindValue(":age", user->age());
    query.exec();

    if (!query.isActive())
        throw DBException("Unable to insert the data to the database");
}

void SqlUserRepository::update(QSharedPointer<User> user) {
    if (user.isNull())
        return;

    QSqlQuery query(m_db);
    query.prepare("update users set firstname = :firstname, lastname = :lastname, age = :age where id = :id");
    query.bindValue(":id", user->id());
    query.bindValue(":firstname", user->firstName());
    query.bindValue(":lastname", user->lastName());
    query.bindValue(":age", user->age());
    query.exec();

    if (!query.isActive())
        throw DBException("Unable to update the data in the database");
}

void SqlUserRepository::remove(QSharedPointer<User> user) {
    if (user.isNull())
        return;

    QSqlQuery query(m_db);
    query.prepare("delete from users where id = :id");
    query.bindValue(":id", user->id());
    query.exec();

    if (!query.isActive())
        throw DBException("Unable to remove the data from the database");
}

QSharedPointer<User> SqlUserRepository::userFromQuery(QSqlQuery& query) {
    int id = query.value("id").toInt();
    QString firstName = query.value("firstname").toString();
    QString lastName = query.value("lastName").toString();
    int age = query.value("age").toInt();
    QSharedPointer<User> user =
        QSharedPointer<User>::create(id, firstName, lastName, age);
    return user;
}

void SqlUserRepository::connectToDatabase() {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(":memory:");
    if (!m_db.open())
        throw DBException("Unable to open the database.");
}

void SqlUserRepository::checkConfiguration() {
    if (!thereIsUsersTable())
        createUsersTable();
}

bool SqlUserRepository::thereIsUsersTable() {
    m_db.tables().contains("users");
}

void SqlUserRepository::createUsersTable() {
    QSqlQuery query;
    query.exec("create table users ("
               "id int primary key, "
               "firstname nvarchar(40), "
               "lastname nvarchar(40), "
               "age int)");

    if (!query.isActive())
        throw DBException("Unable to create users table");
}

SqlUserRepository::DBException::DBException(const char* message) :
    std::logic_error(message) {
}
