/*
true (benar) -> 1
false (salah) -> 0
ukuran memori -> 1 byte
*/

#include <iostream>

int main()
{
    bool lulus = true;
    bool tidak_lulus = false;
    bool naik_kelas = lulus || !tidak_lulus;

    std::cout << naik_kelas << std::endl;

    return 0;
}