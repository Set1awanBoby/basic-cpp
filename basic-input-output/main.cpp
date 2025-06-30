/*
input = mengambil data dari pengguna
output = menampilkan data ke layar
iostream = input dan output
std::cin -> digunakan untuk mengambil data dari pengguna
std::cout -> digunakan untuk menampilkan data ke layar
std::cerr -> digunakan untuk menampilkan pesan kesalahan ke layar
std::clog -> digunakan untuk menampilkan pesan log ke layar

>> (extraction operator) -> digunakan untuk mengambil data dari pengguna
<< (insertion operator) -> digunakan untuk menampilkan data ke layar
*/

#include <iostream>
#include <string>

int main()
{
    int umur;
    std::string nama_lengkap;
    std::cout << "Masukkan nama anda: ";
    std::getline(std::cin, nama_lengkap);
    // getline digunakan untuk mengambil teks dari pengguna yang mengandung spasi
    std::cout << "Masukkan umur anda: ";
    std::cin >> umur;
    std::cout << "Nama anda adalah: " << nama_lengkap << std::endl;
    std::cout << "Umur anda adalah: " << umur << std::endl;

    std::cerr << "Ini adalah pesan kesalahan" << std::endl;
    std::clog << "Ini adalah pesan log" << std::endl;

    return 0;
}