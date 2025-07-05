/*
Pointer to class adalah pointer yang menunjuk ke objek dari sebuah class.
Artinya, kita menyimpan alamat objek class dalam sebuah pointer,
lalu mengakses anggota class (data atau fungsi) melalui pointer tersebut.

1. Dinamis(Heap Memory) - jika objek dibuat secara dinamis
2. Polimorfisme(inheritance) – saat menggunakan class turunan dan virtual function.
3. Efisiensi – lebih efisien jika objek besar dan kita ingin menghindari salinan data.

*/

#include <iostream>
#include <string>

class Mobil
{
public:
    std::string nama;

    void showInfo()
    {
        std::cout << "Nama mobil: " << nama << std::endl;
    }
};

class Pesawat
{
public:
    std::string nama;
    int tahun_keluaran;

    void showInfo()
    {
        std::cout << "Nama Pesawat: " << nama << std::endl;
        std::cout << "Keluaran Tahun: " << tahun_keluaran << std::endl;
    }
};

class Manusia
{
public:
    virtual void talk()
    {
        std::cout << "Vamos" << std::endl;
    }
};

class Orang : public Manusia
{
public:
    void talk() override
    {
        std::cout << "Hala Madrid" << std::endl;
    }
};

int main()
{
    Mobil mobil1;
    Mobil *mobilPointer;
    mobilPointer = &mobil1;

    mobilPointer->nama = "Ferrari";
    mobilPointer->showInfo();
    std::cout << "\n";

    Pesawat *pesawatPoint1 = new Pesawat;
    pesawatPoint1->nama = "Airbus A350 XWB";
    pesawatPoint1->tahun_keluaran = 2010;
    pesawatPoint1->showInfo();

    delete pesawatPoint1;
    std::cout << "\n";

    Pesawat *pesawatPoint2 = new Pesawat[2];
    pesawatPoint2[0].nama = "Boeing 777-300ER";
    pesawatPoint2[0].tahun_keluaran = 1994;

    pesawatPoint2[1].nama = "Airbus A380-800";
    pesawatPoint2[1].tahun_keluaran = 2005;

    for (int i = 0; i < 2; i++)
    {
        std::cout << "Nama Pesawat: " << pesawatPoint2[i].nama << std::endl;
        std::cout << "Tahun Keluaran: " << pesawatPoint2[i].tahun_keluaran << std::endl;
    }

    delete[] pesawatPoint2;
    std::cout << "\n";

    Manusia *manusiaPoint;
    Orang orang;

    manusiaPoint = &orang;
    manusiaPoint->talk();

    return 0;
}