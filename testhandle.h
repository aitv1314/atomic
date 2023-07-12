#ifndef TESTHANDLE_H_INCLUDED
#define TESTHANDLE_H_INCLUDED

#include <atomic>

class TestHandle{
public:
    enum owner{
        CHEN,
        DE,
        LIAN,
    };

public:
    TestHandle();
    ~TestHandle();

public:
    std::atomic<owner> owner_;

public:
    owner getOwner();
    void setOwner(const owner ow);
};

#endif // TESTHANDLE_H_INCLUDED
