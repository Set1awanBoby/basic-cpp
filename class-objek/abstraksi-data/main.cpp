/*
Abstraksi data merupakan salah satu fitur yang paling penting dan esensial
dari pemrograman berorientasi objek dalam C++.
Abstraksi berarti hanya menampilkan informasi penting dan mengabaikan
detailnya. Abstraksi data mengacu pada penyediaan hanya informasi penting
tentang data ke dunia luar, mengabaikan detail atau implementasi yang tidak perlu.

1. abstraksi melalui kelas
2. abstraksi melalui kelas abstrak dan fungsi virtual
*/

#include <iostream>

class BankAcc
{
protected:
    double saldo;

public:
    BankAcc(double saldo) : saldo(saldo) {}

    virtual void tabung(double jumlah) = 0;

    void withdraw(double jumlah)
    {
        if (jumlah <= saldo)
        {
            saldo -= jumlah;
            std::cout << "Penarikan berhasil, silahkan ambil uang anda " << std::endl;
        }
        else
        {
            std::cout << "tidak ada saldo pada atm kamu" << std::endl;
        }
    }

    double lihatsaldo() const
    {
        return saldo;
    }
};

class TabungAkun : public BankAcc
{
public:
    TabungAkun(double saldo) : BankAcc(saldo) {}

    void tabung(double jumlah) override
    {
        saldo += jumlah;
        std::cout << "jumlah deposit uang: " << jumlah << std::endl;
        std::cout << "jumlah uang sekarang: Rp." << saldo << std::endl;
    }
};

int main()
{
    TabungAkun myAcc(250000.00);
    myAcc.tabung(200000.00);
    myAcc.withdraw(50000.00);
    std::cout << "saldo sekarang: Rp." << myAcc.lihatsaldo() << std::endl;

    return 0;
}