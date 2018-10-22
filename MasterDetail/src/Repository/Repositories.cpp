#include "Repository/MockSqlUserRepository.h"
#include "Repository/Repositories.h"

namespace {
QSharedPointer<UserRepository> userRepositoryGlobalInstance(new MockSqlUserRepository());
}

QSharedPointer<UserRepository> Repositories::userRepository() {
    return userRepositoryGlobalInstance;
}
