/*
1. stream
    - input stream
    - output stream
2.  fstream: input dan output
    ifstream: -> membaca file
    ofstream: -> menulis file
    fstream: -> untuk membaca dan menulis file
3.  ios::in -> membuka file untuk membaca
    ios::out -> membuka file untuk menulis
    ios::app -> menambah data ke akhir file
    ios::binary -> membuka file dalam mode biner
    ios::trunc -> memotong isi file jika sudah ada

1. Membuka file dengan menggunakan objek dari kelas, ifstream, ofstream, fstream
2. Melakukan operasi file membaca, menulis, dan keduanya
3. menutup file dengan menggunakan metode .close();

*/

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

class Siswa
{
private:
    std::string nama;
    int kelas;
    double nilai;

public:
    Siswa(std::string nama, int kelas, double nilai) : nama(nama), kelas(kelas), nilai(nilai) {}

    Siswa() : nama(""), kelas(0), nilai(0.0) {}

    void saveToFile(const std::string &filename)
    {
        std::ofstream outFile(filename, std::ios::app);
        if (outFile.is_open())
        {
            outFile << "nama: " << nama << ", kelas: " << kelas << ", nilai: " << nilai << std::endl;
            outFile.close();
            std::cout << "data berhasil ditambahkan " << std::endl;
        }
        else
        {
            std::cout << "ada permasalahan saat menulis file" << std::endl;
        }
    }

    static void readFile(const std::string &filename)
    {
        std::ifstream inFile(filename);
        if (inFile.is_open())
        {
            std::string line;
            std::cout << "membaca file " << filename << std::endl;
            while (getline(inFile, line))
            {
                std::cout << line << std::endl;
            }
            inFile.close();
        }
        else
        {
            std::cout << "Ada Kesalahan ketika membaca file" << std::endl;
        }
    }

    void showInfo() const
    {
        std::cout << "\n";
        std::cout << "nama: " << nama << std::endl;
        std::cout << "kelas: " << kelas << std::endl;
        std::cout << "nilai: " << nilai << std::endl;
        std::cout << "\n";
    }
};

int main()
{

    Siswa siswa1("Boby", 12, 97.5);
    Siswa siswa2("Dontol", 12, 55.0);

    std::string filename = "data_siswa.txt";
    siswa1.saveToFile(filename);
    siswa2.saveToFile(filename);

    Siswa::readFile(filename);

    siswa1.showInfo();
    siswa2.showInfo();

    return 0;
}