#include <iostream>
#include <atomic>

#include "testhandle.h"

TestHandle::TestHandle()
{
    owner_.store(CHEN, std::memory_order_relaxed);
    std::cout << "now create TestHandle object!" << std::endl;
};
TestHandle::~TestHandle()
{
    std::cout << "now delete TestHandle object!" << std::endl;
};

TestHandle::owner TestHandle::getOwner()
{
    return owner_.load(std::memory_order_relaxed);
}
void TestHandle::setOwner(const owner ow)
{
    owner_.store(ow, std::memory_order_relaxed);
}
