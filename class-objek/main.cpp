/*
class Nama_Kelas {
    ... akses modifikasi -> public, private, protected
    ... data member (atribut)
    ... member function (metode)
}

*/

#include <iostream>
#include <string>
#include <iomanip>

class Mobil
{
public: // -> bisa diakses di luar class dan fungsi
    std::string merek_mobil;
    int tahun;

    void displayInfoMobil()
    {
        std::cout << "Merek Mobil: " << merek_mobil << std::endl;
        std::cout << "Tahun Keluaran: " << tahun << std::endl;
    }
};

class Orang
{
private:
    double gaji;

public:
    std::string nama;
    int tahun_lahir;
    int tahun_sekarang;

    void setGaji(double gajiBaru)
    {
        gaji = gajiBaru;
    }

    void showGaji()
    {
        std::cout << "gaji kamu adalah: " << std::setprecision(15) << gaji << std::endl;
    }

    void umurSekarang()
    {
        std::cout << nama << " umur kamu sekarang adalah " << tahun_sekarang - tahun_lahir << std::endl;
    }
};

int main()
{
    Mobil mobil1;
    Mobil mobil2;
    mobil1.merek_mobil = "Porsche";
    mobil1.tahun = 2011;
    mobil1.displayInfoMobil();

    std::cout << "\n";

    mobil2.merek_mobil = "Toyota";
    mobil2.tahun = 2005;
    mobil2.displayInfoMobil();

    std::cout << "\n";

    Orang orang1;
    // orang1.gaji = 200033232.21; // -> error karna private member
    orang1.setGaji(2000000.00);
    orang1.showGaji();
    orang1.nama = "Boby";
    orang1.tahun_lahir = 2006;
    orang1.tahun_sekarang = 2025;
    orang1.umurSekarang();

    return 0;
}