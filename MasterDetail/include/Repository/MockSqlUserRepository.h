#ifndef MOCSQLUSERREPOSITORY_H
#define MOCSQLUSERREPOSITORY_H

#include "SqlUserRepository.h"

class MockSqlUserRepository : public SqlUserRepository {
public:
    MockSqlUserRepository();

protected:
    void fillDatabeseWithMocData();
};

#endif // MOCSQLUSERREPOSITORY_H
