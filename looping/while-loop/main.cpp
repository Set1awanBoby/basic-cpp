/*
while (kondisi) {
    ... <- statement kode yang akan diulang
            berdasarkan kondisi
}

1. Jumlah iterasi tidak diketahui
2. perulangan yang bergantung pada kondisi yang dinamis
*/

#include <iostream>

int main()
{
    int i = 1;      // inisialisasi data
    while (i <= 10) // kondisi
    {
        std::cout << i << " "; // statement kode
        i++;                   // pembaruan data
    }

    std::cout << std::endl;

    double saldo = 1000000.0;
    double bunga = 0.5;
    int tahun = 0;

    while (saldo < 2000000.0)
    {
        saldo += saldo * bunga;
        tahun++;
    }

    std::cout << "Setelah " << tahun << " tahun, saldo anda menjadi " << saldo << std::endl;

    return 0;
}