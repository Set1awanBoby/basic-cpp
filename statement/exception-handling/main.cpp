/*
Dalam C++, exception adalah masalah atau kesalahan tak terduga yang
terjadi saat program sedang berjalan.

C++ menyediakan fitur bawaan untuk menangani pengecualian menggunakan blok try dan catch.
Ini adalah mekanisme penanganan pengecualian di mana kode yang dapat
menyebabkan pengecualian ditempatkan di dalam blok try dan kode yang
menangani pengecualian ditempatkan di dalam blok catch.

throwing exception (throw)
try
catch

stdexcept std::out_of_range std::invalid_argument std::runtime_error

try {
    throw exception;
} catch (tipe_exception variabel) {
    ...
}
*/

#include <iostream>
#include <stdexcept>

class CostumException : public std::exception
{
private:
    std::string pesan;

public:
    explicit CostumException(const std::string pesan) : pesan(pesan) {}

    const char *what() const noexcept override
    {
        return pesan.c_str();
    }
};

class Calc
{
public:
    double divide(double num1, double num2)
    {
        if (num2 == 0)
        {
            throw std::invalid_argument("Error: tidak bisa dibagikan dengan nol!");
        }
        return num1 / num2;
    }
};

int main()
{
    /*
    Calc kalkulator;
    double num1, num2;

    std::cout << "Masukan angka 1: ";
    std::cin >> num1;
    std::cout << "Masukan angka 2: ";
    std::cin >> num2;

    try
    {
        double hasil = kalkulator.divide(num1, num2);
        std::cout << "hasil: " << hasil << std::endl;
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "hasil kalkulasi berhasil!" << std::endl;
*/
    try
    {
        throw CostumException("contoh dari exception buatan sendiri");
    }
    catch (const CostumException &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
