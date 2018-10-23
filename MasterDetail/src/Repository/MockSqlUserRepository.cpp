#include "Repository/MockSqlUserRepository.h"
#include "UserFactory.h"

MockSqlUserRepository::MockSqlUserRepository() {
//	for (int i = 0; i < 100; ++ i)
    fillDatabeseWithMocData();
}

void MockSqlUserRepository::fillDatabeseWithMocData() {
    auto nextAge = [] { return 18 + rand() % 23; };
    insert(UserFactory::create("John", "Doe", nextAge()));
    insert(UserFactory::create("John", "Smith", nextAge()));
    insert(UserFactory::create("Chuck", "Norris", nextAge()));
    insert(UserFactory::create("Jackie", "Chan", nextAge()));
}
