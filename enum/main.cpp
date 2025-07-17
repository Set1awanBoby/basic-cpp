/*
Dalam C++, enumerasi adalah tipe data yang ditentukan pengguna yang terdiri dari
sekumpulan konstanta integer bernama. Tipe ini membantu dalam menetapkan
nama yang bermakna pada nilai integer guna meningkatkan keterbacaan dan
kemudahan pemeliharaan kode.

Secara default, variabel pertama dalam enum diberi nilai integer 0, '
dan variabel berikutnya bertambah 1.

Setelah itu, kita dapat membuat variabel untuk enum ini dan
menetapkan konstanta nama yang telah didefinisikan di dalamnya.
*/
#include <iostream>

enum Warna
{
    Merah,  // -> 0
    Kuning, // -> 1
    Hijau,  // -> 2
};

enum Hari
{
    Senin = 1,
    Selasa, // -> 2
    Rabu = 15,
    Kamis // -> 16
};

enum class Hewan
{
    Kudanil,
    Gajah,
    Kucing,
};

enum Gelas
{
    GelasWine = 3,
    GelasMinum = 7
};

enum Lampu
{
    Off,
    On
};

void printLampu(Lampu lampu)
{
    if (lampu == On)
    {
        std::cout << "Lampu nyala" << std::endl;
    }
    else
    {

        std::cout << "Lampu mati" << std::endl;
    }
};

int main()
{
    Warna warnaSaya = Merah;

    std::cout << "warna dari merah adalah " << warnaSaya << std::endl;

    if (warnaSaya == Hijau)
    {
        std::cout << "warnanya sama hijau " << std::endl;
    }
    else
    {
        std::cout << "warnanya tidak sama hijau " << std::endl;
    }

    std::cout << "\n";

    Hari hariSaya = Kamis;
    std::cout << "nilai dari hari kamis: " << Kamis << std::endl;

    std::cout << "\n";

    Hewan peliharaan = Hewan::Kucing;

    if (peliharaan == Hewan::Kucing)
    {
        std::cout << "peliharaan saya adalah kucing" << std::endl;
    };

    // std::cout << "Value" << peliharaan << std::endl; -> error
    std::cout << "\n";

    Gelas gelasSaya = GelasWine;

    std::cout << "value dari si gelas wine adalah: " << static_cast<int>(gelasSaya) << std::endl;
    std::cout << "\n";

    Lampu lampu = Off;
    printLampu(lampu);
    return 0;
}