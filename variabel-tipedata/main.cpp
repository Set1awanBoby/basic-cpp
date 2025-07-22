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

    const int PI = 3.14;  // konstanta -> tidak bisa diubah
    volatile int ab = 10; // mutable -> bisa diubah

    int a = 5, b = 6; // copy-initialization
    int c(7), d(8);   // direct-initialization
    int e{9}, f{10};  // direct-list-initialization
    int i{}, j{};     // value-initialization

    /*
    int a -> akan menghasilkan nilai random jika tidak di isi value ny
    int b{} -> akan menghasilkan nilai 0 jika tidak ada value ny
    */
    int a;
    int b{};
    [[maybe_unused]] double gravity{9.8}; // Don't complain if gravity is unused
    return 0;
}
