#include <QtTest>

#include "UserFactory.h"

class TestUserFactory : public QObject {
    Q_OBJECT

private slots:
    void testCreateUser();
    void testCreateUser_data();

    void testCloneUser();
    void testCloneUser_data();

protected:
    void universalUserData();
};

void TestUserFactory::testCreateUser() {
    QFETCH(QString, firstname);
    QFETCH(QString, lastname);
    QFETCH(int, age);

    QSharedPointer<User> user = UserFactory::create(firstname, lastname, age);

    QVERIFY(user->isValid());
    QCOMPARE(user->firstName(), firstname);
    QCOMPARE(user->lastName(), lastname);
    QCOMPARE(user->age(), age);
}

void TestUserFactory::testCreateUser_data() {
    universalUserData();
}

void TestUserFactory::testCloneUser() {
    QFETCH(QString, firstname);
    QFETCH(QString, lastname);
    QFETCH(int, age);

    QSharedPointer<User> user = UserFactory::create(firstname, lastname, age);

    QSharedPointer<User> cloned = UserFactory::clone(user);

    QVERIFY(!cloned.isNull());
    QCOMPARE(*user, *cloned);
}

void TestUserFactory::testCloneUser_data() {
    universalUserData();
}

void TestUserFactory::universalUserData() {
    QTest::addColumn<QString>("firstname");
    QTest::addColumn<QString>("lastname");
    QTest::addColumn<int>("age");

    QTest::addRow("1") << "John" << "Doe" << 25;
    QTest::addRow("2") << "John" << "Smith" << 53;
    QTest::addRow("3") << "Chuck" << "Norris" << 34;
    QTest::addRow("4") << "Jackie" << "Chan" << 35;
}

QTEST_APPLESS_MAIN(TestUserFactory)

#include "tst_testuserfactory.moc"
