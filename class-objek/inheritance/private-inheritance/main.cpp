/*
pewarisan privat menjadikan anggota publik dan yang dilindungi
dari kelas dasar menjadi privat dalam kelas turunan.

class Base {
    ...
};

class Derived : private Base {
    ...
};

*/

#include <iostream>
#include <string>

class Mesin
{
private:
    int tenaga_mesin;

protected:
    std::string jenisBBM;

public:
    Mesin(int t, std::string bbm) : tenaga_mesin(t), jenisBBM(bbm) {}

    void infoMesin()
    {
        std::cout << "Tenaga mesin: " << tenaga_mesin << " HP" << std::endl;
        std::cout << "Jenis Bahan bakar: " << jenisBBM << std::endl;
    }
};

class Mobil : private Mesin
{
private:
    std::string namaMobil;
    std::string perusahaan;

public:
    Mobil(std::string n, std::string p, int t, std::string bbm) : Mesin(t, bbm), namaMobil(n), perusahaan(p) {}

    void infoMobil()
    {
        std::cout << "Nama Mobil: " << namaMobil << std::endl;
        std::cout << "Perusahaan: " << perusahaan << std::endl;
        infoMesin();
    }

    void setBBM(std::string bbm)
    {
        jenisBBM = bbm;
    }
};

int main()
{

    Mobil mobil("Porsche 911 gt3 rs", "Porsche", 518, "Aftur");
    mobil.infoMobil();
    std::cout << "\n";
    mobil.setBBM("Pertalite");
    mobil.infoMobil();
    mobil.infoMesin(); // -> error karna bersifat private dikelas turunan

    return 0;
}