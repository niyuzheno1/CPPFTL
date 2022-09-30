//hello world
#include <iostream>
#include "CPPFTL/export.h"
using namespace CPPFTL;
int main()
{
    Fuzzer<int> fuzzer;
    fuzzer.setSeed(0);
    fuzzer.setType(TYPE_NUMERIC);
    fuzzer.setRange(0, 100);
    fuzzer.setSize(10);
    fuzzer.setIsDifferent(true);
    fuzzer.generate();
    for(auto &x : fuzzer){
        std::cout << x << std::endl;
    }
    return 0;
}
