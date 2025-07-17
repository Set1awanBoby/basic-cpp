/*
efek dari double delete / double free ->
- Bisa menyebabkan crash program
- Bisa menyebabkan korupsi memori
- Bisa tidak ada error sama sekali, tapi memicu bug misterius
- Bisa membuka kerentanan keamanan (security vulnerability)

int *angka = new int(10);
    std::cout << *angka << std::endl;

    delete angka;
    delete angka; // akan muncul error
*/
#include <iostream>
#include <memory>

int main()
{
    int *angka1 = new int(10);
    std::cout << *angka1 << std::endl;

    delete angka1;
    angka1 = nullptr;
    delete angka1; // -> tidak ada error jika sudah diset ke nullptr

    std::unique_ptr<int> angka2 = std::make_unique<int>(10);
    std::cout << *angka2 << std::endl;
    // dengan memanfaatkan smart pointer

    return 0;
}
