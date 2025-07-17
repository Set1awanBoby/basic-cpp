/*
Terjadi karena:
- kode korup
- kesalahan kompilasi
*/

#include <iostream>
#include <csignal>
#include <cstdlib>

void signalHandle(int nilaiSignal)
{
    std::cerr << std::endl
              << "Info Signal: " << nilaiSignal << std::endl;
    std::exit(nilaiSignal);
};

int main()
{
    std::signal(SIGILL, signalHandle);

    /*
    std::cout << "program berjalan, coba test instruksi illegal" << std::endl;
    typedef void (*FuncPtr)();
    FuncPtr function_invalid = reinterpret_cast<FuncPtr>(0x1);
    function_invalid();
    */

    std::cout << "esekusi instruksi assembly illegal";
    asm("ud2");
    std::cout << "program tidak berjalan" << std::endl;
    return 0;
}