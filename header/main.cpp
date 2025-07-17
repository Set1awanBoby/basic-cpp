
#include <iostream>
// #include "include/operasi_matematika.hpp"
//   g++ -o main main.cpp include/operasi_matematika.cpp

#include "include/kotak.hpp"

int main()
{
    /*
        int a = 10, b = 30;

        std::cout << "Pertambahan: " << tambah(a, b) << std::endl;
        std::cout << "Pengurangan: " << kurang(a, b) << std::endl;
    */
    Kotak kotak1(5.0, 3.0);

    std::cout << "area kotak: " << kotak1.area() << std::endl;
    std::cout << "perimeter kotak: " << kotak1.perimeter() << std::endl;

    kotak1.setTinggi(7.0);
    std::cout << "update tinggi: " << kotak1.ambilTinggi() << std::endl;

    // std::cout << luas_sisi(3.5) << std::endl;
}