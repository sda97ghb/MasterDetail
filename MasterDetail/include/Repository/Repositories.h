#ifndef REPOSITORIES_H
#define REPOSITORIES_H

#include "UserRepository.h"

class Repositories {
public:
    static QSharedPointer<UserRepository> userRepository();
};

#endif // REPOSITORIES_H
