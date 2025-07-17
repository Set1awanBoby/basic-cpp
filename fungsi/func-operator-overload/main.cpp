/*
Overloading fungsi C++ memungkinkan Anda untuk mendefinisikan
beberapa fungsi dengan nama yang sama tetapi parameter yang berbeda.
Ini adalah bentuk polimorfisme waktu kompilasi di mana suatu fungsi
dapat melakukan pekerjaan yang berbeda berdasarkan parameter yang berbeda
yang diberikan kepadanya.
Ini adalah fitur pemrograman berorientasi objek
yang meningkatkan keterbacaan program.

Operator Overloading C++ memiliki kemampuan untuk memberikan operator
makna khusus untuk tipe data tertentu, kemampuan ini dikenal sebagai
operator overloading. Misalnya, kita dapat menggunakan operator penjumlahan (+)
untuk string guna menggabungkan dua string dan untuk integer guna
menambahkan dua integer. Operator << dan >> adalah operator binary shift
tetapi juga digunakan dengan aliran input dan output.
Hal ini dimungkinkan karena operator overloading.
*/

#include <iostream>

class HitungLuas
{
public:
    double hitung_luas(double r) { return 3.14 * r * r; }
    int hitung_luas(int s) { return s * s; }
    int hitung_luas(int p, int l) { return p * l; }
};

class Complex
{
private:
    double real;
    double imaginer;

public:
    Complex(double r = 0, double i = 0) : real(r), imaginer(i) {}
    Complex operator+(const Complex &nilai)
    {
        return Complex(real + nilai.real, imaginer + nilai.imaginer);
    }

    void show() const
    {
        std::cout << real << " + " << imaginer << "i" << std::endl;
    }
};

int main()
{
    HitungLuas hitungLuas;
    std::cout << "Luas dari lingkaran jari jari 7: " << hitungLuas.hitung_luas(7.0) << std::endl;
    std::cout << "Luas dari Persegi sisi 5: " << hitungLuas.hitung_luas(5) << std::endl;
    std::cout << "Luas dari Persegi Panjang P:8 dan L:6: " << hitungLuas.hitung_luas(8, 6) << std::endl;
    std::cout << "\n";

    Complex bilanganComplex1(3.0, 4.0);
    Complex bilanganComplex2(1.5, 2.5);

    Complex hasil = bilanganComplex1 + bilanganComplex2;
    std::cout << "nilai complex pertama: ";
    bilanganComplex1.show();
    std::cout << "nilai complex kedua: ";
    bilanganComplex2.show();
    std::cout << "nilai complex1 + complex2: ";
    hasil.show();

    return 0;
}