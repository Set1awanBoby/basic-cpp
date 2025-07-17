#include <iostream>
#include <csignal>
#include <cstdlib>
#include <cassert>

void signalHandler(int nilaiSignal)
{
    std::cout << "Info Signal " << nilaiSignal << std::endl;
    std::exit(nilaiSignal);
}

int main()
{
    /*
    std::cout << "program dijalankan.." << std::endl;
    std::cout << "program ga jelass.. abort dah kata guwahj" << std::endl;
    std::abort();
    std::cout << "ini proses yang jalan ..." << std::endl;
    */
    /*
    std::signal(SIGABRT, signalHandler);
    std::cout << "Program jalan" << std::endl;
    std::cout << "Errorororor!!" << std::endl;
    std::abort();
    std::cout << "line ini tidak akan diesekusi" << std::endl;
    */

    int x = 5;

    std::cout << "check assert " << std::endl;
    assert(x == 10);
    std::cout << "p ini jalan kaga?" << std::endl;
    return 0;
}