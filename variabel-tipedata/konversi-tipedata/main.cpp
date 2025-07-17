/*
Konversi tipe berarti mengonversi satu tipe data ke tipe lain
yang kompatibel sehingga tidak kehilangan maknanya.
Konversi tipe sangat penting untuk mengelola berbagai tipe data dalam C++.

1. implicit conevrsion
2. explicit conversion

    C-style (type) konversi
    C++
    static_cast -> Digunakan untuk konversi tipe waktu kompilasi standar,
    dynamic_cast -> Digunakan untuk konversi tipe runtime dalam polimorfisme dan pewarisan,
    const_cast -> Menghapus atau menambahkan kualifikasi const atau volatile,
    reinterpret_cast -> Digunakan untuk interpretasi ulang bit tingkat rendah (misalnya, mengonversi pointer)
*/

#include <iostream>

class Jarak
{
private:
    int meter;

public:
    Jarak(int m) : meter(m) {}
    Jarak() : meter(0) {}

    operator int() const
    {
        return meter;
    }

    void jarakSekarang() const
    {
        std::cout << "Jarak sekarang: " << meter << "m" << std::endl;
    }
};

int main()
{
    int intNum = 22;
    double decimalNum = intNum;

    std::cout << intNum << std::endl;
    std::cout << decimalNum << std::endl;
    std::cout << "\n";

    double PI = 3.14;
    int intPI = (int)PI;
    std::cout << PI << std::endl;
    std::cout << intPI << std::endl;
    std::cout << "\n";
    // static_cast
    int intPIstatic = static_cast<int>(PI);
    std::cout << intPIstatic << std::endl;
    std::cout << "\n";

    Jarak jarak(200);
    int meter = jarak;
    jarak.jarakSekarang();
    std::cout << "Jarak sekarang versi variabel: " << meter << std::endl;
    std::cout << "\n";

    /*
    Tidak bisa mengkonversi dari tipedata yang besar ke tipedata yang kecil;
    */
    int nilai_besar = 100000;
    short nilai_kecil = (short)nilai_besar;

    std::cout << nilai_besar << std::endl;
    std::cout << nilai_kecil << std::endl;
    return 0;
}