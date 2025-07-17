/*
Enkapsulasi didefinisikan sebagai pembungkusan data dan informasi dalam satu unit.
Dalam Pemrograman Berorientasi Objek, enkapsulasi didefinisikan sebagai
pengikatan data dan fungsi yang memanipulasinya.

Dalam C++, enkapsulasi OOP diimplementasikan menggunakan kelas dan
penentu akses yang menjaga data dan metode manipulasi tetap tertutup dalam satu unit.
Keuntungan langsung dari pengemasan ini adalah hanya komponen yang
diperlukan yang terlihat oleh pengguna, dan informasi lainnya disembunyikan.


*/
#include <iostream>
#include <string>

class BankAcc
{
private:
    std::string namaAcc;
    double saldo;

public:
    BankAcc(std::string n, double s)
    {
        namaAcc = n;
        saldo = s;
    }

    std::string getNamaAkun() const
    {
        return namaAcc;
    }

    void setNamaAkun(std::string nama)
    {
        if (!nama.empty())
        {
            namaAcc = nama;
        }
        else
        {
            std::cout << "Kamu memasukan field salah" << std::endl;
        }
    }

    double ambilSaldo() const
    {
        return saldo;
    }

    void deposit(double jumlah)
    {
        if (jumlah > 0)
        {
            saldo += jumlah;
            std::cout << "Deposit sejumlah: " << jumlah << std::endl;
            std::cout << "Jumlah uang sekarang adalah: Rp." << saldo << std::endl;
        }
        else
        {
            std::cout << "Invalid" << std::endl;
        }
    }

    void withdraw(double jumlah)
    {
        if (jumlah > 0 && jumlah <= saldo)
        {
            saldo -= jumlah;
            std::cout << "Menarik uang sebanyak: Rp." << jumlah << std::endl;
            std::cout << "Saldo sekarang: Rp." << saldo << std::endl;
        }
        else
        {
            std::cout << "Kamu memasukan nilai salah!" << std::endl;
        }
    }
};

int main()
{
    BankAcc myAcc("Boby", 400000.00);
    std::cout << "Nama Pemilik Akun: " << myAcc.getNamaAkun() << std::endl;
    std::cout << "Saldo dari pemilik akun " << myAcc.getNamaAkun() << " : Rp."
              << myAcc.ambilSaldo() << std::endl;
    myAcc.deposit(200000.00);
    myAcc.withdraw(400000.00);
    return 0;
}