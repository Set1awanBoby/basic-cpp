/*
this adalah pointer khusus yang tersedia dalam setiap fungsi anggota
(member function) dari sebuah class.
Pointer ini menunjuk ke objek saat ini — yaitu
objek yang sedang memanggil fungsi tersebut.

1. Membedakan antara parameter dan data member jika namanya sama
2. Mengembalukan refrensi objek saat method chaining
3. Menunjuk alamat objek saat ini (misalnya dalam debug)
4. tidak bisa dimodifikasi
5. tidak tersedia dalam fungsi static

*/

#include <iostream>

class Kubus
{
private:
    int sisi;

public:
    Kubus(int s)
    {
        this->sisi = s;
    }

    void displayKubus()
    {
        std::cout << "Luas kubus: " << 6 * (sisi * sisi) << std::endl;
    }
};

class Balok
{
private:
    int panjang, lebar, tinggi;

public:
    Balok &setPanjang(int p)
    {
        this->panjang = p;
        return *this;
    }
    Balok &setLebar(int l)
    {
        this->lebar = l;
        return *this;
    }
    Balok &setTinggi(int t)
    {
        this->tinggi = t;
        return *this;
    }

    void luasBalok()
    {
        std::cout << "Luas balok: " << 2 * (panjang * lebar + panjang * tinggi + lebar * tinggi);
    }
};

class Age
{
private:
    int age1, age2;

public:
    Age(int a, int b) : age1(a), age2(b) {}

    bool apakahSama(const Age &compareUmur) const
    {

        return (this == &compareUmur);
    };
};

class Kotak
{
private:
    int lebar, tinggi;

public:
    Kotak(int l, int t) : lebar(l), tinggi(t) {}

    Kotak &operator+=(const Kotak &nilaiAlamat)
    {
        this->lebar += nilaiAlamat.lebar;
        this->tinggi += nilaiAlamat.tinggi;
        return *this;
    }

    void showCalc()
    {
        std::cout << "lebar: " << lebar << " tinggi: " << tinggi << std::endl;
    }
};

int main()
{

    Kubus kubus1(5);
    kubus1.displayKubus();
    std::cout << "\n";

    Balok balok1;
    balok1.setPanjang(6).setLebar(3).setTinggi(5).luasBalok();
    std::cout << "\n";

    Age umur1(10, 20);
    Age umur2(10, 20);

    if (umur1.apakahSama(umur1))
    {
        std::cout << "umur kamu sama" << std::endl;
    }
    if (!umur1.apakahSama(umur2))
    {
        std::cout << "umur kamu tidak sama" << std::endl;
    }

    std::cout << "\n";

    Kotak kotak1(10, 20);
    Kotak kotak2(5, 10);

    kotak1 += kotak2;

    kotak1.showCalc();

    return 0;
}