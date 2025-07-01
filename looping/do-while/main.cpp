/*
do {
    ... <- statement kode yang akan diulang
            berdasarkan kondisi

} while (kondisi); <- kondisi akan diulang jika bernilai true

jika true -> statement kode akan diulang
jika false -> statement kode tidak akan diulang

1. esekusi minimal 1 kali
2. mudah dibaca
3. fleksibel
*/

#include <iostream>

int main()
{
    int angka, faktorial = 1;
    std::cout << "Masukkan angka faktorial: ";
    std::cin >> angka;

    do
    {
        faktorial *= angka;
        angka--;
    } while (angka > 0); // -> looping akan berhenti jika angka bernilai 0

    std::cout << faktorial << std::endl;

    return 0;
}