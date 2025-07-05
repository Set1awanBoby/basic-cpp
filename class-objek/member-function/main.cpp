/*
1. deklarasi
    - member function dideklarasikan di dalam definisi kelas
    - bisa dideklarasikan dibagian modifikasi akses -> public, private, protected
2. definisi -> inline function :: <- scope resolution
3. aksesbilitas

1. inline member function
2. outline member function
3. static member function
4. const member function
5. friend function

class member function adalah sebuah fungsi yang dideklarasikan
didalam class untuk mendefinisikan perilaku dan objek
*/

#include <iostream>
#include <string>

// inline function
class Mobil
{
public:
    std::string nama;

    void showInfoMobil()
    {
        std::cout << "Nama Mobil: " << nama << std::endl;
    }
};

// outline member function
class Orang
{
public:
    std::string nama;

    void showNama();
};

void Orang::showNama()
{
    std::cout << "nama: " << nama << std::endl;
};

// static member function
class Count
{
private:
    static int countNum;

public:
    static void tambah()
    {
        countNum++;
    }

    static void showCount()
    {
        std::cout << "Count: " << countNum << std::endl;
    }
};
int Count::countNum = 0;

// const member function
class Pesawat
{
private:
    std::string nama;
    int tahun_keluar;

public:
    Pesawat(std::string n, int t) : nama(n), tahun_keluar(t)
    {
    }

    void showInfo() const
    {
        std::cout << "Nama Pesawat: " << nama << std::endl;
        std::cout << "Keluaran Tahun: " << tahun_keluar << std::endl;
    }
};

// friend member function
class Kotak
{
private:
    double lebar;

public:
    Kotak(double l) : lebar(l) {}

    friend void showInfoKotak(const Kotak &k);
};

void showInfoKotak(const Kotak &k)
{
    std::cout << "Lebar kotak: " << k.lebar << std::endl;
};

//
class Motor
{
private:
    std::string nama;

public:
    Motor(std::string n) : nama(n) {}

    void showInfoMotor()
    {
        std::cout << "Nama Motor: " << this->nama << std::endl;
    }
};

int main()
{
    // inline member function
    Mobil mobil1;
    mobil1.nama = "Ferrari";
    mobil1.showInfoMobil();

    std::cout << "\n";

    // outline member function
    Orang orang1;
    orang1.nama = "Boby";
    orang1.showNama();

    std::cout << "\n";

    // static member function
    Count count1;
    count1.tambah();
    count1.showCount();
    Count::tambah();
    count1.showCount();

    std::cout << "\n";

    // const member function
    const Pesawat pesawat1("Boeing 787-9 Dreamliner", 2009);
    pesawat1.showInfo();

    std::cout << "\n";

    // friend member function
    Kotak kotak1(5.5);
    showInfoKotak(kotak1);

    std::cout << "\n";

    //
    Motor motor1("Ducati Desmosedici");
    motor1.showInfoMotor();
    return 0;
}