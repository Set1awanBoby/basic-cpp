/*
Public inheritance menjadikan anggota publik dari kelas dasar menjadi
publik dalam kelas turunan, dan anggota yang dilindungi dari kelas dasar
tetap dilindungi dalam kelas turunan.

class Base {
    ...
};

class Derived : public Base {
    ...
};

*/

#include <iostream>
#include <string>

class Kendaraan
{
protected:
    std::string nama;
    int kecepatan;

public:
    Kendaraan(std::string n, int k) : nama(n), kecepatan(k) {}

    void infoKendaraan()
    {
        std::cout << "Nama: " << nama << std::endl;
        std::cout << "Kecepatan: " << kecepatan << std::endl;
    }

    virtual void klakson()
    {
        std::cout << "Tottttt " << std::endl;
    }
};

class Mobil : public Kendaraan
{
private:
    int kursi;

public:
    Mobil(std::string n, int k, int kursi) : Kendaraan(n, k), kursi(kursi) {}

    void infoKursi()
    {
        std::cout << "Jumlah kursi mobil: " << kursi << std::endl;
    }

    void klakson() override
    {
        std::cout << nama << " bersuara: prottprott" << std::endl;
    }
};

int main()
{

    Kendaraan kendaraan("base kendaraan", 80);
    kendaraan.infoKendaraan();
    kendaraan.klakson();

    Mobil mobil("BMW M4", 250, 4);
    mobil.infoKendaraan();
    mobil.infoKursi();
    mobil.klakson();

    // tidak bisa mengambil info kursi karna bersifat private
    Kendaraan *kendaraanPoint = &mobil;
    kendaraanPoint->infoKendaraan();
    kendaraanPoint->klakson();
    return 0;
}
