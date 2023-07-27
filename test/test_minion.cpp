#include <iostream>

#include "Minion.hpp"
#include "Transmitter.hpp"

using namespace dfs;

int main()
{
    Minion minion(1234);

    minion.Wait();

    std::cout << "STOP SERVER" << std::endl;

    return 0;
}