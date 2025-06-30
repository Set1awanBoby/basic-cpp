// variabel
// - nama -> identitas
// - tipe data -> jenis data yang disimpan
// - nilai -> data
// - deklarasi -> mendeklarasikan variabel

// tipe data
// - jenis informasi -> bilangan bulat,desimal,huruf,boolean
// - berapa banyak ruang memori yang akan digunakan
// - tipe data harus sesuai dengan nilai yang disimpan

#include <iostream>
#include <string>

int main()
{
    int umur = 20;             // bilangan bulat
    float ipk = 3.5;           // bilangan desimal
    char huruf = 'a';          // huruf
    std::string nama = "boby"; // teks
    bool lulus = true;         // boolean
    double pi = 3.14;          // bilangan desimal lebih besar

    const int PI = 3.14; // konstanta -> tidak bisa diubah
    volatile int a = 10; // mutable -> bisa diubah
    return 0;
}
