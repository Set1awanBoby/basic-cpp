/*
Inheritance (pewarisan) adalah konsep dalam pemrograman berorientasi objek (OOP)
di mana sebuah class (anak) mewarisi properti (data member)
dan perilaku (fungsi member) dari class lain (induk).

Tujuan utama: reusabilitas kode dan membuat hierarki class.

base class
derived class

Akses Modifier dalam pewarisan
    - public inheritance
    - protected inheritance
    - private inheritance

overriding dan polimorfisme
*/

#include <iostream>
#include <string>

// base class
class Hewan
{
protected:
    std::string nama;
    int umur;

public:
    Hewan(std::string n, int u) : nama(n), umur(u) {}

    void infoHewan()
    {
        std::cout << "Nama: " << nama << std::endl;
        std::cout << "Umur: " << umur << std::endl;
    }

    virtual void suara()
    {
        std::cout << "Hewan bersuara " << std::endl;
    }
};

// derived class
class Kucing : public Hewan
{
public:
    Kucing(std::string n, int u) : Hewan(n, u) {}

    void suara() override
    {
        std::cout << nama << " Bersuara: Miawwwww" << std::endl;
    }
};

int main()
{
    Hewan hewan("dasar hewan", 5);
    hewan.infoHewan();
    hewan.suara();

    Kucing kucing("fello", 2);
    kucing.infoHewan();
    kucing.suara();
    std::cout << "\n";

    Hewan *hewanPoint;
    hewanPoint = &kucing;
    hewanPoint->infoHewan();
    hewanPoint->suara();

    return 0;
}