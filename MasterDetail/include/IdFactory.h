#ifndef IDFACTORY_H
#define IDFACTORY_H

class IdFactory {
public:
    static int nextId();
private:
    static int m_lastEmittedId;
};

#endif // IDFACTORY_H
