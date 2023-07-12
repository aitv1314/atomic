#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <windows.h>
#include <string.h>
#include <cstring>

#include "test.h"
#include "testhandle.h"

using namespace std;

TestHandle Test::th;

void Test::init()
{
    id = (int)getpid();
    strcpy(name,"chendelian");
    que.push(id);
    setTestHandleOwner(TestHandle::LIAN);
};
void Test::run()
{
    string s = name;
    int id = !que.empty()>0 ? que.back() : 0;

    std::cout << "id is :" << getTestId() << "\ndata in que is :" << id << "\nname is :" << s << "\n" <<std::endl;
};
void Test::tick()
{
    while(1)
    {
        run();
        sleep(1);
        ++id;
        que.push(id);
    }
};
int Test::getTestId(void)
{
    return id;
};
void Test::setTestHandleOwner(TestHandle::owner ow)
{
    th.setOwner(ow);
};

int main(int argc, char** argv)
{
    /*****************
    char buf[100] = {0};
    cin.getline(buf,5);
    std::cout<<"your input is :"<< buf<<std::endl;
    *****************/

    /*****************
    char buf1[] = "hello world , print error now£¡\nerror error error";
    cerr << "Error msg is :" << buf1 <<endl;
    ******************/
    Test T;

    T.init();
    T.run();
    T.tick();

    return 0;
}
