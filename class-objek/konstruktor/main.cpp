/*
1. nama constructor sama dengan nama kelas
2. tidak memiliki return, termasuk void
3. dapat menerima parameter
4. dipanggil secara otomatis saat si objek dibuat

jenis constructor:
- default constructor -> tidak memiliki parameter
- parameterized constructor -> memiliki parameter
- copy constructor -> membuat model salinan dari objek lain
*/

#include <iostream>
#include <string>

class Mobil
{
public:
    std::string nama;
    int tahun_keluaran;

    Mobil() // -> default constructor
    {
        nama = "Porsche";
        tahun_keluaran = 2012;
    }

    void showInfoMobil()
    {
        std::cout << "Nama Mobil: " << nama << std::endl;
        std::cout << "Tahun keluaran: " << tahun_keluaran << std::endl;
    }
};

class Siswa
{
public:
    std::string nama;
    int kelas;

    Siswa(std::string n, int k) // -> parameterized constructor
    {
        nama = n;
        kelas = k;
    }

    void showInfoSiswa()
    {
        std::cout << "Nama: " << nama << std::endl;
        std::cout << "Kelas: " << kelas << std::endl;
    }
};

class Streamer
{
public:
    std::string nama_channel;
    int kode_channel;

    Streamer(std::string n, int k)
    {
        nama_channel = n;
        kode_channel = k;
    }

    Streamer(const Streamer &objek)
    {
        nama_channel = objek.nama_channel;
        kode_channel = objek.kode_channel;
    }

    void showInfoStreamer()
    {
        std::cout << "Nama channel: " << nama_channel << std::endl;
        std::cout << "Kode channel: " << kode_channel << std::endl;
    }
};

int main()
{
    // default constructor
    Mobil mobil1, mobil2;
    mobil1.showInfoMobil();
    mobil2.nama = "Scania";
    mobil2.tahun_keluaran = 2017;
    mobil2.showInfoMobil();

    std::cout << "\n";

    // parameterized constructor
    Siswa siswa1("Boby", 12);
    Siswa siswa2("Jang wonyoung", 12);
    siswa1.showInfoSiswa();
    siswa2.showInfoSiswa();

    std::cout << "\n";

    // copy constructor
    Streamer streamer1("DeanKT", 1212);
    Streamer streamer2 = streamer1;
    streamer1.showInfoStreamer();
    streamer2.showInfoStreamer();

    return 0;
}