/*
Praprosesor dalam C++ adalah alat yang memproses kode sebelum dikompilasi
oleh kompiler. Praprosesor melakukan banyak tugas seperti
memasukkan berkas header, kompilasi bersyarat, substitusi teks,
menghapus komentar, dan sebagainya. Praprosesor juga memungkinkan
pengembang untuk memilih bagian kode mana yang akan disertakan atau dikecualikan.

Dalam C++, direktif praprosesor adalah perintah khusus yang digunakan
untuk memberi instruksi kepada praprosesor.
Perintah ini diawali dengan simbol '#' dan memberi tahu praprosesor untuk
memodifikasi kode sumber sebelum dikompilasi. Terdapat berbagai
direktif praprosesor dalam C++ untuk berbagai operasi.

- #include -> menghubungkan header file dari suatu source code
- #define -> membuat sebuah simbol atau macro konstanta
- #undef -> menghapus sebuah macro yang telah didefinisikan
- #if , #elif , #else , #endif -> kompilasi yang bersyarat berdasarkan beberapa ekspresi
- #ifdef , #ifndef -> kompilasi yang bersyarat pada ada atau tidaknya makro.
- #error -> Menghentikan proses kompilasi dan menghasilkan pemberitahuan kesalahan.
- #warning -> saat kompilasi, pemberitahuan warning akan ditampilkan
- #pragma -> Berikan instruksi spesifik kepada kompiler.
*/

#include <iostream>
#define PI 3.14

#define Hello "Hello World"
#undef Hello

#define DEBUG_MODE

#define VERSIAPLIKASI 3

#ifndef VERSIGAME 1
#error "VERSIGAME tidak didefinisikan"
#endif

int main()
{
    std::cout << "Luas lingkaran dengan rad 7: " << PI * 7 * 7 << std::endl;
    // std::cout << Hello << std::endl; -> error

#ifdef DEBUG_MODE
    std::cout << "mode debug diaktifkan" << std::endl;
#else
    std::cout << "mode debug tidak diaktifkan" << std::endl;
#endif

#if VERSIAPLIKASI == 1
    std::cout << "versi aplikasi v1 diaktifkan" << std::endl;
#elif VERSIAPLIKASI == 2
    std::cout << "versi aplikasi v2 diaktifkan" << std::endl;
#elif VERSIAPLIKASI == 3
    std::cout << "versi aplikasi v3 diaktifkan" << std::endl;
#endif
    return 0;
}