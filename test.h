#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <string.h>

#include "testhandle.h"

#define GLOBAL_NAME_LEN             32

class Test{
private:
    int id;

public:
    char name[GLOBAL_NAME_LEN];
    std::queue<int> que;

public:
    void init();
    void run();
    void tick();
    static TestHandle th;

    int getTestId(void);
    void setTestHandleOwner(TestHandle::owner ow);

};
#endif // TEST_H_INCLUDED
