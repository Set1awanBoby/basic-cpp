/*
goto nama_label <- digunakan untuk menghentikan eksekusi kode

name_label:
    ... <- kode yang akan dilompat
*/

#include <iostream>
#include <string>

int main()
{
    /*
    std::cout << "Hello World" << std::endl;

    goto lompat;
    std::cout << "Kode ini tidak akan dijalankan" << std::endl;

lompat:
    std::cout << "Kode ini akan dijalankan" << std::endl;*/

    int angka;

    std::cout << "Masukkan angka positif: ";
    std::cin >> angka;

    if (angka < 0)
    {
        goto angka_negatif;
    }

    std::cout << "kamu memasukan angka " << angka << std::endl;
    return 0;

angka_negatif:
    std::cout << "error: kamu memasukan angka negatif: " << angka << std::endl;

    return 1;
}