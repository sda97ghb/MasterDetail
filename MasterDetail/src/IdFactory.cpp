#include "IdFactory.h"

int IdFactory::m_lastEmittedId = -1;

int IdFactory::nextId() {
    ++ m_lastEmittedId;
    return m_lastEmittedId;
}
