#include <QtTest>
#include <UserFactory.h>

#include <Repository/SqlUserRepository.h>
#include <Repository/UserRepository.h>

class TestUsersRepository : public QObject {
    Q_OBJECT

private slots:
    void testInsertAndGetById();
    void testGetAll();
    void testGetNonexistent();
    void testGetNonexistent2();
    void testUpdate();
    void testRemove();

protected:
    bool equalsLists(QList<QSharedPointer<User>> users1,
                     QList<QSharedPointer<User>> users2);
};

void TestUsersRepository::testInsertAndGetById() {
    QSharedPointer<UserRepository> repo =
        QSharedPointer<SqlUserRepository>::create();
    QSharedPointer<User> srcUser = UserFactory::create("John", "Doe", 25);

    repo->insert(srcUser);

    QSharedPointer<User> dstUser = repo->byId(srcUser->id());
    QVERIFY(!dstUser.isNull());
    QCOMPARE(*dstUser, *srcUser);
}

void TestUsersRepository::testGetAll() {
    QSharedPointer<UserRepository> repo =
        QSharedPointer<SqlUserRepository>::create();
    QList<QSharedPointer<User>> srcUsers = {
        UserFactory::create("John", "Doe", 25),
        UserFactory::create("John", "Smith", 35),
        UserFactory::create("Chuck", "Norris", 55),
        UserFactory::create("Jackie", "Norris", 45)
    };
    for (auto user : srcUsers)
        repo->insert(user);

    QList<QSharedPointer<User>> dstUsers = repo->allUsers();

    QVERIFY(equalsLists(dstUsers, srcUsers));
}

void TestUsersRepository::testGetNonexistent() {
    QSharedPointer<UserRepository> repo =
        QSharedPointer<SqlUserRepository>::create();

    QSharedPointer<User> user = repo->byId(100);

    QVERIFY(user.isNull());
}

void TestUsersRepository::testGetNonexistent2() {
    QSharedPointer<UserRepository> repo =
        QSharedPointer<SqlUserRepository>::create();

    QList<QSharedPointer<User>> users = repo->allUsers();

    QVERIFY(users.isEmpty());
}

void TestUsersRepository::testUpdate() {
    QSharedPointer<UserRepository> repo =
        QSharedPointer<SqlUserRepository>::create();
    QSharedPointer<User> srcUser = UserFactory::create("John", "Doe", 25);
    repo->insert(srcUser);

    QSharedPointer<User> modifyedUser = UserFactory::clone(srcUser);
    modifyedUser->setFirstName("Chackie");
    modifyedUser->setLastName("Chan");
    modifyedUser->setAge(36);

    repo->update(modifyedUser);

    QSharedPointer<User> dstUser = repo->byId(srcUser->id());

    QVERIFY(!dstUser.isNull());
    QCOMPARE(*dstUser, *modifyedUser);
}

void TestUsersRepository::testRemove() {
    QSharedPointer<UserRepository> repo =
        QSharedPointer<SqlUserRepository>::create();
    QSharedPointer<User> srcUser = UserFactory::create("John", "Doe", 25);
    repo->insert(srcUser);

    QSharedPointer<User> dstUser = repo->byId(srcUser->id());
    QVERIFY(!dstUser.isNull());
    QCOMPARE(*dstUser, *srcUser);

    repo->remove(srcUser);

    dstUser = repo->byId(srcUser->id());
    QVERIFY(dstUser.isNull());
}

bool TestUsersRepository::equalsLists(QList<QSharedPointer<User>> users1,
                                      QList<QSharedPointer<User>> users2) {
    for (auto user1 : users1) {
        bool userIsPresentInBothCollections = false;
        for (auto user2 : users2)
            if ((*user1) == (*user2))
                userIsPresentInBothCollections = true;
        if (!userIsPresentInBothCollections)
            return false;
    }
    for (auto user2 : users2) {
        bool userIsPresentInBothCollections = false;
        for (auto user1 : users1)
            if ((*user1) == (*user2))
                userIsPresentInBothCollections = true;
        if (!userIsPresentInBothCollections)
            return false;
    }
    return true;
}

QTEST_APPLESS_MAIN(TestUsersRepository)

#include "tst_testusersrepository.moc"
