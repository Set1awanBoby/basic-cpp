/*
struct (kependekan dari structure) adalah tipe data komposit
yang memungkinkan pengelompokan beberapa variabel
(disebut anggota atau field) dengan tipe data berbeda menjadi satu kesatuan
atau mungkin bisa disebut sebuah objek

struct namaStruct {
    std::string nama;
    int umur;
    float ipk;
    dan lain lain...
} -> nama struct juga bisa di deklarasi di atas atau di bawah sini
*/

#include <iostream>
#include <string>

struct Mahasiswa
{
    std::string nama;
    int umur;
    float ipk;
};

int main()
{
    Mahasiswa mhs1, mhs2;
    mhs1.nama = "boby";
    mhs1.umur = 20;
    mhs1.ipk = 3.5;

    mhs2 = {"dontol", 21, 2.4};

    std::cout << "Nama: " << mhs1.nama << std::endl;
    std::cout << "Umur: " << mhs1.umur << std::endl;
    std::cout << "IPK: " << mhs1.ipk << std::endl;

    std::cout << "\n";

    std::cout << "Nama: " << mhs2.nama << std::endl;
    std::cout << "Umur: " << mhs2.umur << std::endl;
    std::cout << "IPK: " << mhs2.ipk << std::endl;
    return 0;
}