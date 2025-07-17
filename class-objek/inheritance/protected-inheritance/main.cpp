/*
Pewarisan yang dilindungi menjadikan anggota kelas dasar yang
publik dan dilindungi menjadi terlindungi dalam kelas turunan.

class Base {
    ...
};

class Derived : protected Base {
    ...
};

*/

#include <iostream>
#include <string>

class Organisasi
{
protected:
    std::string nama;

public:
    Organisasi(std::string n) : nama(n) {}

    void infoOrganisasi()
    {
        std::cout << "nama organisasi: " << nama << std::endl;
    }
};

class Departemen : protected Organisasi
{
private:
    std::string nama_dp;

public:
    Departemen(std::string n, std::string nama_dp) : Organisasi(n), nama_dp(nama_dp) {}

    void infoDepartemen()
    {
        std::cout << "Nama Departemen: " << nama_dp << std::endl;
    }

    void gantiNamaOrganisasi(std::string n)
    {
        nama = n;
    }
};

int main()
{

    Departemen dept("NgodangNgoding", "WPU");
    dept.infoDepartemen();
    dept.gantiNamaOrganisasi("yaya");
    dept.infoOrganisasi(); // -> error karna bersifat protected dikelas turunan

    return 0;
}