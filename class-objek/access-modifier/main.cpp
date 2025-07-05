/*
access modifiers atau access specifiers dalam suatu kelas digunakan
untuk menetapkan aksesibilitas kepada anggota kelas, yaitu,
mereka menetapkan beberapa batasan pada anggota kelas sehingga
mereka tidak dapat diakses secara langsung oleh fungsi luar.
Pengubah akses digunakan untuk mengimplementasikan aspek penting
dari Pemrograman Berorientasi Objek yang dikenal sebagai Penyembunyian Data.

1. public
2. private
3. protected
*/

#include <iostream>
#include <string>
#include <iomanip>

// public -> Semua anggota kelas yang dideklarasikan
// di dalam public specifier akan bisa diakses di luar dari kelas tsb.
class Orang
{
public:
    std::string nama;

    void Greetings()
    {
        std::cout << "Hello " << nama << std::endl;
    }
};

// private -> Anggota kelas yang dideklarasikan sebagai private
// hanya dapat diakses oleh fungsi anggota di dalam kelas.
class GenshinChara
{
private:
    std::string nama;

public:
    //  GenshinChara(std::string n) : nama(n) {}

    void setNameChara(std::string n)
    {
        nama = n;
    }

    void showGenshinChara()
    {
        std::cout << "Nama Chara: " << nama << std::endl;
    }
};

// protacted -> mirip dengan akses privat dalam artian
// ia tidak dapat diakses di luar kelasnya kecuali
// dengan bantuan kelas teman.
class F1Team
{
protected:
    std::string name;

public:
    void setName(std::string n)
    {
        name = n;
    };
};

class Team : public F1Team
{
public:
    void displayTeam()
    {
        std::cout << "Nama Team: " << name << std::endl;
    }
};

class BankAccount
{
private:
    double saldo;

protected:
    std::string nama;

public:
    BankAccount(std::string n, double s) : nama(n), saldo(s) {};

    void deposit(double jumlah)
    {
        if (jumlah > 0)
        {
            saldo += jumlah;
            std::cout << "Saldo berhasil ditambah" << std::endl;
        }
        else
        {
            std::cout << "Jumlah saldo harus positif" << std::endl;
        };
    };

    void showInfoAccount()
    {
        std::cout << "Nama Akun: " << nama << std::endl;
        std::cout << "Jumlah Saldo: Rp." << std::setprecision(15) << saldo << std::endl;
    };
};

int main()
{
    Orang orang1;
    orang1.nama = "Boby";
    orang1.Greetings();

    std::cout << "\n";

    // GenshinChara chara1("Ganyu");
    // chara1.showGenshinChara();
    GenshinChara chara2;
    chara2.setNameChara("Skirik");
    chara2.showGenshinChara();

    std::cout << "\n";

    Team team1;
    team1.setName("Red Bull Racing");
    team1.displayTeam();

    std::cout << "\n";

    BankAccount akun1("Boby", 2500000);
    akun1.deposit(1500000);
    akun1.showInfoAccount();

    return 0;
}
